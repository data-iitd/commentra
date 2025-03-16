import os
import re
import argparse
import logging
import time
from pathlib import Path
from tqdm import tqdm
from model import DecoderBase, make_model
from accelerate import Accelerator


def generate_comments(args, workdir: Path, model: DecoderBase, accelerator: Accelerator = None):
    EXTENSIONS = {"C": ".c", "C++": ".cpp", "Java": ".java", "Python": ".py", "Go": ".go"}

    if accelerator:
        model = accelerator.unwrap_model(model)

    # Input folder path
    in_folder = f'/home/codetrans/dataset/{args.dataset}/{args.source_lang}/Code'
    in_files = os.listdir(in_folder)
    print(f'found {len(in_files)} inputs')
    total_time = 0

    for f in tqdm(in_files):
        prompt_file = f'{in_folder}/{f}'
        p_name = f[:(-1 * len(EXTENSIONS[args.source_lang]))]  # Extract code_id
        
        output_dir = os.path.join(
            '/home/codetrans/dataset',
            args.generated_comments,
            args.source_lang,
            'Code'
        )
        os.makedirs(output_dir, exist_ok=True)  # Create output directory if it doesn't exist

        log = f"Generate comments for file: {p_name} in {args.source_lang}-{args.dataset} using {args.model}"
        n_existing = 0
        if args.resume:
            # count existing translated files
            n_existing = len(
                [
                    f
                    for f in os.listdir(os.path.join(output_dir, p_name))
                    if f.endswith(EXTENSIONS[args.target_lang])
                ]
            )
            if n_existing > 0:
                log += f" (resuming from {n_existing})"

        nsamples = args.n_samples - n_existing
        
        logging.info(log)
        code_data=''
        with open(prompt_file, 'r', encoding="utf-8") as file:
            code_data = file.read()
            code_data= re.sub(r'public\s*class\s*[^{]+', r'public class ' + "Main ", code_data)
            code_data = code_data.replace(p_name,'Main')

        INTENT = {"what": "describes the functionality of a method", "why": "explains the reason why a method is provided", "how-it-is-done": "describes the implementation details of a method"}

        # prompt = f'''You are an helpful comment generating agent. I am giving you a {args.source_lang} code below. I want you to generate suitable comments to {INTENT[args.intent]} and insert it into the code.
        
        # Prompt for inline comments
        # prompt = f'''You are an helpful comment generating agent. I am giving you a {args.source_lang} code below. I want you to generate suitable comments for each logical blocks and insert it into the code.
        
        # prompt = f'''You are an expert code analysis agent. Below, I will provide you with code written in {args.source_lang}. Please analyze the code and generate clear, language-agnostic pseudocode that outlines its logic and structure. Ensure that the pseudocode is easy to understand and highlights the main functionalities.
        # Your output must clearly mark the beginning and end of the pseudocode using the following pattern:
        # --- Start of Pseudocode ---
        # [pseudocode here]
        # --- End of Pseudocode ---

        # prompt = f'''You are a helpful comment generating agent. I am providing you with some {args.source_lang} code below. Your task is to first analyze the code and identify the top 60% of methods or logical blocks that are most critical for understanding the code’s functionality. Then, generate and insert suitable comments only for those selected parts, leaving the remaining code unmodified.

        prompt = f'''You are a helpful comment generating agent. I am giving you a {args.source_lang} code below. I want you to generate suitable comments for each method and insert them above the method definitions. Do not add any comments inside the methods.


        

#######
Code
#######

'''
        prompt += code_data
        prompt += "\n\nLet's think step by step"

        # print(prompt)

        t0 = time.perf_counter()

        # Generate the code with comments
        sidx = args.n_samples - nsamples
        while sidx < args.n_samples:
            
            outputs = model.codegen(prompt,
                do_sample=not args.greedy,
                num_samples=args.n_samples - sidx,
                max_length=args.max_length,
            )

            assert outputs, "No outputs from model!"
            for impl in outputs:
                # Directory to store generated comments for the current file
                output_file_dir = os.path.join(output_dir, p_name)
                os.makedirs(output_file_dir, exist_ok=True)  # Create output directory if it doesn't exist
                
                # Path for saving the specific output file
                output_file_path = os.path.join(output_file_dir, f"{sidx}{EXTENSIONS[args.source_lang]}")

                try:
                    with open(output_file_path, "w", encoding="utf-8") as f:
                        if model.conversational:
                            f.write(impl)
                        else:
                            f.write(prompt + impl)
                except UnicodeEncodeError:
                    continue
                sidx += 1
        t1 = time.perf_counter()
        print("Generation time for", p_name, ":", t1 - t0)
        total_time+=( t1 - t0)
    print("Avg generation time of run:", total_time / len(in_files))
    logging.info(f"Avg generation time of run: {total_time / len(in_files)}")


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--model", required=True, type=str)
    parser.add_argument("--batch_size", default=1, type=int)
    parser.add_argument("--temperature", default=0.0, type=float)
    parser.add_argument("--dataset", required=True, type=str, choices=["codenet", "avatar", "benchmark", "benchmark_uc", "sample", "JAB_uncommented"])
    parser.add_argument("--source_lang", required=True, type=str, choices=["C", "C++", "Java", "Python", "Go"])
    parser.add_argument("--n_samples", default=1, type=int)
    parser.add_argument("--generated_comments", required=True, type=str)
    parser.add_argument("--intent", required=True, type=str)
    parser.add_argument("--resume", action="store_true")
    parser.add_argument("--greedy", action="store_true")
    parser.add_argument("--ngpus", default=1, type=int)
    parser.add_argument("--max_length", default=1024, type=int)

    accelerator = Accelerator()
    args = parser.parse_args()

    # Multi-GPU handling
    gpus_str = ",".join(str(i) for i in range(args.ngpus))
    os.environ["CUDA_VISIBLE_DEVICES"] = gpus_str

    if args.greedy and (args.temperature != 0 or args.batch_size != 1 or args.n_samples != 1):
        args.temperature = 0
        args.batch_size = 1
        args.n_samples = 1
        print("Greedy decoding ON (--greedy): setting batch_size=1, n_samples=1, temperature=0")

    args.root = "/home/codetrans/Project/data/comment_generation/"
    
    # Make project directory for approach and dataset
    os.makedirs(args.root, exist_ok=True)
    os.makedirs(os.path.join(args.root, args.dataset), exist_ok=True)

    # Model creation and setup
    args.model = args.model.lower()
    model = make_model(
        name=args.model, batch_size=args.batch_size, temperature=args.temperature, ngpus=args.ngpus
    )
    model = accelerator.prepare(model)

    # Directory for commented code output
    workdir = os.path.join(
        args.root,
        args.dataset,
        args.model,
        args.source_lang,
        f"temperature_{args.temperature}"
    )
    os.makedirs(workdir, exist_ok=True)

    with open(os.path.join(workdir, "model.txt"), "w") as f:
        f.write(str(model.__dict__))

    logging.basicConfig(filename=os.path.join(workdir, 'log.log'), level=logging.INFO, format='%(asctime)s %(levelname)s %(module)s - %(funcName)s: %(message)s', datefmt='%Y-%m-%d %H:%M:%S')
    logging.info(f"Comment generation started with args: {args}")

    generate_comments(args, workdir=workdir, model=model, accelerator=accelerator)

    logging.info(f"Comment generation finished")


if __name__ == "__main__":
    main()
