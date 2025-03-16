"""
We used a simple heuristic to clean the generations of the open-source models. Feel free to play with the extraction
heuristic to get better results.
"""

import os
import re
import argparse
'''
pseudocode approach cleaning-
1. Start, End
2.# End of Code

#specific to java cleaning 
    # -care public class cleaning 
    # re.sub(r'public\s*class\s*[^{]+', r'public class ' + "atcoder_ABC17_B" , s1)


'''
def find_smallest_index(text, strings=["Code summary:", "Explanation:", "End of Code","pseudocode algorithm:"]):
    text_lower = text.lower()  # Convert text to lowercase
    strings_lower = [s.lower() for s in strings]  # Convert strings to lowercase

    indices = [text_lower.find(s) for s in strings_lower]
    valid_indices = [idx for idx in indices if idx != -1]
    
    if valid_indices:
        return min(valid_indices)
    else:
        return -1

def list_files(startpath):
    files = []
    for root, dirs, walkfiles in os.walk(startpath):
        for name in walkfiles:
            files.append(os.path.join(root, name))

    return files


def clean_codegeex(dataset):
    main_path = f'output/CodeGeeX/{dataset}'
    output_path = 'output/CodeGeeX/'

    files = list_files(main_path)

    for f in files:

        splitted = f.split('/')
        filename = splitted[-1].strip()
        target_lang = splitted[-2].strip()
        source_lang = splitted[-3].strip()

        with open(f, 'r') as file:
            data = file.read()

        valid_lines = []
        for line in data.split('\n'):
            if line.strip() in ['C:', 'C++:', 'Java:', 'Python:', 'Go:', '"""']:
                break
            else:
                valid_lines.append(line)
        
        data = '\n'.join(valid_lines)
        data = data.replace('<|endoftext|>', '')
        data = data.replace(f'```{target_lang.lower()}', '')
        data = data.replace(f'```', '')

        if target_lang == 'Java':
            data = re.sub('public\s*class\s*.+', 'public class ' + filename.split('.')[0] + ' {', data)
        
        if target_lang == 'Java' and dataset == 'evalplus':
            data = 'package com.example;\n' + data

        os.makedirs(output_path + dataset + '/' + source_lang + '/' + target_lang, exist_ok=True)
        with open(output_path + dataset + '/' + source_lang + '/' + target_lang + '/' + filename, 'w') as file:
            file.write(data)


def clean_codegen(dataset):
    main_path = f'output/CodeGen/{dataset}'
    output_path = 'output/CodeGen/'

    files = list_files(main_path)

    for f in files:
        print(f)
        splitted = f.split('/')
        filename = splitted[-1].strip()
        target_lang = splitted[-2].strip()
        source_lang = splitted[-3].strip()

        with open(f, 'r') as file:
            data = file.read()

        data = data[data.find(f'{target_lang} Code:')+len(f'{target_lang} Code:'):].strip()        

        valid_lines = []
        for line in data.split('\n'):
            if line.strip() in ["*/", 'C Code:', 'C++ Code:', 'Java Code:', 'Python Code:', 'Go Code:']:
                break
            else:
                valid_lines.append(line)
        
        data = '\n'.join(valid_lines)
        data = data.replace('<|endoftext|>', '')

        if target_lang == 'Java':
            data = re.sub('public\s*class\s*.+', 'public class ' + filename.split('.')[0] + ' {', data)

        if target_lang == 'Java' and dataset == 'evalplus' and 'package com.example;' not in data:
            data = 'package com.example;\n' + data

        os.makedirs(output_path + dataset + '/' + source_lang + '/' + target_lang, exist_ok=True)
        with open(output_path + dataset + '/' + source_lang + '/' + target_lang + '/' + filename, 'w',encoding="utf-8") as file:
            file.write(data)



def clean_starcoder(dataset):
    main_path = f'/home/scai/mtech/aib222684/MTP/output_cot_orig_full/StarCoder/{dataset}'
    output_path = '/home/scai/mtech/aib222684/MTP/output_cot_orig/StarCoder/'

    files = list_files(main_path)

    for f in files:
        print(f)
        splitted = f.split('/')
        filename = splitted[-1].strip()
        target_lang = splitted[-2].strip()
        source_lang = splitted[-3].strip()

        #specific to java cleaning
        # if (target_lang!="Java"):
        #     continue

        if (target_lang=="__pycache__"):
            continue
        with open(f, 'r',encoding="utf-8") as file:
            data = file.read()
        
        data = data[data.find('<fim_suffix><fim_middle>')+len('<fim_suffix><fim_middle>'):]
        '''
        # cleaning of summary 
        # last_index=data.find('End of Code')
        last_index=find_smallest_index(data)
        if (last_index==-1):
            if (target_lang!="Python"):# else last } in java code
                last_index =data.rfind("}")+1
                data=data[:last_index]
        else:
            data=data[:last_index]
        # some error possibility if not found as -1


        # cleaning of pseudocode 
        last_index=find_smallest_index(data)
        if (last_index==-1):
            if (target_lang!="Python"):# else last } in java code
                last_index =data.rfind("}")+1
                data=data[:last_index]
        else:
            data=data[:last_index]
        # some error possibility if not found as -1
        '''
        # cleaninig of icl
        # 5. Java code:
        '''
        if (target_lang=="Python"):
            last_index=data.find("5. Java code:")
            if (last_index!=-1 ):# 
                data=data[:last_index]
        elif (target_lang=="Java"):
            last_index=data.find("5. Python code:")
            if (last_index!=-1 ):# 
                data=data[:last_index]
        '''
        # cleaning of autocot2d
        data = data[data.find('3. Python Code:')+len('3. Python Code:'):]

        # cleaning of autocot1
        # data = data[data.find('3. Whole Python Code:')+len('3. Whole Python Code:'):]

        last_idx =data.find('####################')
        if (last_idx==-1):
            # last_idx=data.find("4. Whole Java Code:")
            last_idx=data.find("4. Java Code:")
        if (last_idx==-1):
            last_idx =data.find("main()")
            if (last_idx!=-1):
                last_idx+=len("main()")
        if (last_idx!=-1):
            data =data[:last_idx]

        # b/w -substring
        #  or startwith '''
        # last_idx =data.find(f"```{target_lang.lower()}")
        
        # main() -> main(self) in autocot2d
        # data = data.replace("def main()", "def main(self)")

        valid_lines = []
        for line in data.split('\n'):
            # Start-End due to pseudocode part
            if line.strip() in ["'''","```",'End','C Code:', 'C++ Code:', 'Java Code:', 'Python Code:', 'Go Code:', '"""'] or line.strip().startswith("Input") or line.strip().startswith("Output"):
                break
            elif line.strip()=='Start' or line.strip().startswith("```") or line.strip()==target_lang:
                continue
            else:
                valid_lines.append(line)
        
        data = '\n'.join(valid_lines)
        data = data.replace('<|endoftext|>', '')

        if target_lang == 'Java':
            # data = re.sub('public\s*class\s*.+', 'public class ' + filename.split('.')[0] + ' {', data)
            data= re.sub(r'public\s*class\s*[^{]+', r'public class ' + filename.split('.')[0], data)

        if target_lang == 'Java' and dataset == 'evalplus' and 'package com.example;' not in data:
            data = 'package com.example;\n' + data

        os.makedirs(output_path + dataset + '/' + source_lang + '/' + target_lang, exist_ok=True)
        with open(output_path + dataset + '/' + source_lang + '/' + target_lang + '/' + filename, 'w',encoding="utf-8") as file:
            file.write(data)


import os
import glob
# to clean granite and starcoder

def clean_new_models(dataset):#granite-20b-code-instruct
    target_lang = args.target_lang
    source_lang = args.source_lang
    EXTENSIONS = { "C": ".c", "C++": ".cpp", "Java": ".java", "Python": ".py", "Go": ".go" }
    extn= EXTENSIONS[args.target_lang]
    main_path = f"/home/codetrans/Project/data/codetlingua/{args.approach}/{dataset}/{args.model}/{args.source_lang}/{args.target_lang}/temperature_0.0"
    # output_path= "/scratch/cse/dual/cs5190439/MTP1/PLTranslation_data/codetlingua/autocot2d/avatar/starcoder/Python/Java/temperature_0/"
    # print(main_path)
    output_path =main_path +'/'
    cur_folder_path = main_path
    # print(os.path.join(cur_folder_path, '*'))
    # Loop through all subdirectories in the current folder path
    for dir_path in glob.glob(os.path.join(cur_folder_path, '*')):
        # print(dir_path)
        if os.path.isdir(dir_path):  # Check if it's a directory
            dir_id = os.path.basename(dir_path)  # Extract folder_id as dir_id
            for hh in range(5):
                output_path =main_path +'/'+str(hh)+'/'
                os.makedirs(output_path,exist_ok=True)
                target_file_path = os.path.join(dir_path,f"{hh}{extn}")
                # print(target_file_path)
                if os.path.isfile(target_file_path):  # Check if the file exists
                    with open(target_file_path, 'r', encoding="utf-8") as file:
                        data = file.read()
                    #body
                    # filename=dir_id+".java"
                    filename=dir_id+f"{extn}"
                    # print(filename)
                    # data = data[data.find('<fim_suffix><fim_middle>')+len('<fim_suffix><fim_middle>'):]
                    '''
                    # cleaning of summary 
                    # last_index=data.find('End of Code')
                    last_index=find_smallest_index(data)
                    if (last_index==-1):
                        if (target_lang!="Python"):# else last } in java code
                            last_index =data.rfind("}")+1
                            data=data[:last_index]
                    else:
                        data=data[:last_index]
                    # some error possibility if not found as -1
    
    
                    # cleaning of pseudocode 
                    last_index=find_smallest_index(data)
                    if (last_index==-1):
                        if (target_lang!="Python"):# else last } in java code
                            last_index =data.rfind("}")+1
                            data=data[:last_index]
                    else:
                        data=data[:last_index]
                    # some error possibility if not found as -1
                    '''
                    # cleaninig of icl
                    # 5. Java code:
                    '''
                    if (target_lang=="Python"):
                        last_index=data.find("5. Java code:")
                        if (last_index!=-1 ):# 
                            data=data[:last_index]
                    elif (target_lang=="Java"):
                        last_index=data.find("5. Python code:")
                        if (last_index!=-1 ):# 
                            data=data[:last_index]
                    '''
                    # cleaning of autocot2d 
                    if (args.approach!="vanilla"):
                        # print(f"3. {source_lang} Code:")
                        # print(len(f"3. {source_lang} Code:"))
                        # data = data[data.find(f"3. {source_lang} Code:")+len(f"3. {source_lang} Code:"):]
                        # data = data[data.find(f"3. {target_lang} Code:")+len(f"3. {target_lang} Code:"):]
                        # data = data[data.find(f"//Java code 2:"):]
                        data = data[data.find(f"example_3."):]
                        
                        # print(f'##############{data}')
                        last_idx =data.rfind(f"Complete Python Code:")
                        # print(f'last ind is 0 {last_idx}')
                        if (last_idx==-1):
                            last_idx =data.rfind(f"{target_lang} code:")
    
                        if (last_idx!=-1):
                            # last_idx=data.find("4. Whole Java Code:")
                            last_idx+=len(f"Complete Python Code:")
                            data=data[last_idx:]
    
                        last_idx=data.find("###$###")
                        # print(f'last ind is 1 {last_idx}')
                        # not need with stopping criteria
                        # last_idx=data.find("###$###")
                        if (last_idx!=-1):
                            data =data[:last_idx]
    
                    # vanilla
                    if (args.approach=="vanilla"):
                        last_idx =data.find(f"{args.target_lang}:")
                        
                        if (last_idx!=-1):
                            # last_idx=data.find("4. Whole Java Code:")
                            last_idx+=len(f"{args.target_lang}:")
                            data=data[last_idx:]
                        
                        last_idx=data.find(f"{args.source_lang}:")
                        # if (last_idx==-1):
                        #     last_idx =data.rfind("main()")
                        #     if (last_idx!=-1):
                        #         last_idx+=len("main()")
                        
                        if (last_idx!=-1):
                            data =data[:last_idx]
                        
                    # cleaning of autocot1
                    # data = data[data.find('3. Whole Python Code:')+len('3. Whole Python Code:'):]
    
                    # last_idx =data.find('####################')
                    # if (last_idx==-1):
                    #     # last_idx=data.find("4. Whole Java Code:")
                    #     last_idx=data.find("4. Java Code:")
                    # if (last_idx==-1):
                    #     last_idx =data.find("main()")
                    #     if (last_idx!=-1):
                    #         last_idx+=len("main()")
                    # if (last_idx!=-1):
                    #     data =data[:last_idx]
    
                    # b/w -substring
                    #  or startwith '''
                    # last_idx =data.find(f"{target_lang.lower()}")
                    
                    # main() -> main(self) in autocot2d
                    # data = data.replace("def main()", "def main(self)")
    
#                    valid_lines = []
#                    for line in data.split('\n'):
#                        # Start-End due to pseudocode part
#                        if line.strip() in ["'''","",'End','C Code:', 'C++ Code:', 'Java Code:', 'Python Code:', 'Go Code:', '"""'] or line.strip().startswith("Input") or line.strip().startswith("Output"):
#                            break
#                        elif line.strip()=='Start' or line.strip().startswith("```") or line.strip()==args.target_lang or (line.strip().startswith("#") and args.target_lang!="Python") :#EOS problem of ###$ or comments
#                            continue
#                        else:
#                            valid_lines.append(line)
#                    
#                    data = '\n'.join(valid_lines)
                    
                    data = data.replace('<|endoftext|>', '')
    
                    if args.target_lang == 'Java':
                        # data = re.sub('public\s*class\s*.+', 'public class ' + filename.split('.')[0] + ' {', data)
                        data= re.sub(r'public\s*class\s*[^{]+', r'public class ' + filename.split('.')[0], data)
                        # changes made here
                        data = data.replace('Main', filename.split('.')[0])
                        
                    
    
                    if args.target_lang == 'Java' and dataset == 'evalplus' and 'package com.example;' not in data:
                        data = 'package com.example;\n' + data
    
                    #os.makedirs(output_path + dataset + '/' + args.source_lang + '/' + args.target_lang, exist_ok=True)
                    print(output_path)
                    
                    with open(output_path + filename, 'w',encoding="utf-8") as file:
                        file.write(data)



def clean_codellama(dataset, args):
    print(f"Cleaning dataset: {dataset}, Target Language: {args.target_lang}")  # Debug

    target_lang = args.target_lang
    source_lang = args.source_lang
    EXTENSIONS = { "C": ".c", "C++": ".cpp", "Java": ".java", "Python": ".py", "Go": ".go" }
    extn = EXTENSIONS[target_lang]
    # extn = EXTENSIONS[source_lang]
    
    # Use the correct model name with the correct casing
    main_path = f"/home/codetrans/Project/data/codetlingua/{args.approach}/{dataset}/codellama-13b-instruct-hf/{source_lang}/{target_lang}/temperature_0.0"

    # main_path = f"/home/scai/mtech/aib232083/AJAY/Project/dataset/{dataset}/{source_lang}/Code"
    
    # print(f"Main Path: {main_path}")  # Debug
    # print(f"Main Path exists: {os.path.exists(main_path)}")  # Debug

    # Function to read file up to <END-OF-CODE> and remove starting line with ```python
    def read_until_end_of_code(file_path):
        with open(file_path, 'r', encoding='utf-8') as file:
            lines = []
            recording = False
            for line in file:
                # Skip the starting line containing ```python
                if line.strip() == 'Python:':
                    recording = True
                    continue
                # if line.strip() == 'Java:':
                #     recording = True
                #     continue

                if line.strip() in ['C:', 'C++:', 'Go:']:
                    recording = True
                    continue
                    
                elif line.strip() == '```':
                    recording = False  # Stop recording before this line
                    break  # Stop reading further

                elif line.strip() in ['Translate the above C code to C++ and end with comment "', 'Translate the above C++ code to Java and end with comment "']:
                    recording = False
                    break

                elif line.strip() == 'END-OF-CODE':
                    break
                    
                elif line.strip() == '<END-OF-CODE>':
                    break
                if recording:
                    lines.append(line)
        return ''.join(lines)
        

    # Loop through all subdirectories in the current folder path
    for dir_path in glob.glob(os.path.join(main_path, '*')):
        # print(f"Checking directory: {dir_path}")  # Debug
        if os.path.isdir(dir_path):  # Check if it's a directory
            dir_id = os.path.basename(dir_path)  # Extract folder_id as dir_id
            for hh in range(5):
                output_folder = os.path.join(main_path, str(hh))
                os.makedirs(output_folder, exist_ok=True)
                
                target_file_path = os.path.join(dir_path, f"{hh}{extn}")
                # print(f"Target file path: {target_file_path}")  # Debug

                if os.path.isfile(target_file_path):  # Check if the file exists
                    # Read the file and get the content up to <END-OF-CODE>
                    cleaned_code = read_until_end_of_code(target_file_path)

                    
                    
                    # # Define the cleaned file's output path
                    # cleaned_file_path = os.path.join(output_folder, f"{dir_id}{extn}")
                    
                    filename = f"{dir_id}{extn}"
                    cleaned_file_path = os.path.join(output_folder, filename)
                    with open(cleaned_file_path, 'w', encoding="utf-8") as file:
                        file.write(cleaned_code)  # Write the cleaned code
                    print(f"Saved cleaned file: {cleaned_file_path}")  # Debug
                else:
                    print(f"File does not exist: {target_file_path}")  # Debug


def clean_starcoder(dataset, args):
    print(f"Cleaning dataset: {dataset}, Target Language: {args.target_lang}")  # Debug

    target_lang = args.target_lang
    source_lang = args.source_lang
    EXTENSIONS = { "C": ".c", "C++": ".cpp", "Java": ".java", "Python": ".py", "Go": ".go" }
    extn = EXTENSIONS[target_lang]
    # extn = EXTENSIONS[source_lang]
    
    # Use the correct model name with the correct casing
    main_path = f"/home/codetrans/Project/data/codetlingua/{args.approach}/{dataset}/starcoder/{source_lang}/{target_lang}/temperature_0.0"

    # main_path = f"/home/codetrans/dataset/{dataset}/{source_lang}/Code"
    
    # print(f"Main Path: {main_path}")  # Debug
    # print(f"Main Path exists: {os.path.exists(main_path)}")  # Debug

    # Function to read file up to <END-OF-CODE> and remove starting line with ```python
    def read_until_end_of_code(file_path):
        with open(file_path, 'r', encoding='utf-8') as file:
            lines = []
            recording = True
            for line in file:
                # Skip the starting line containing ```python
                if line.strip() in ('```Python', '```go', 'C:', 'C++:', 'Go:'):
                    recording = True
                    continue
                elif line.strip() == '```':
                    recording = False  # Stop recording before this line
                    break  # Stop reading further

                elif line.strip() == 'Output:':
                    recording = False
                    break
                elif line.strip() in ["'''",'END-OF-CODE', '<END-OF-CODE>', 'Translate the above C++ code to Python and end with comment "', 'Run the above Go code.', 'The above Go code is a complete solution for the problem.', 'The above Go code is a bit more verbose than the Java code, but it is still readable.']:
                    break

                if recording:
                    lines.append(line)
        return ''.join(lines)

    # Loop through all subdirectories in the current folder path
    for dir_path in glob.glob(os.path.join(main_path, '*')):
        #print(f"Checking directory: {dir_path}")  # Debug
        if os.path.isdir(dir_path):  # Check if it's a directory
            dir_id = os.path.basename(dir_path)  # Extract folder_id as dir_id
            for hh in range(5):
                output_folder = os.path.join(main_path, str(hh))
                os.makedirs(output_folder, exist_ok=True)
                
                target_file_path = os.path.join(dir_path, f"{hh}{extn}")
                #print(f"Target file path: {target_file_path}")  # Debug

                if os.path.isfile(target_file_path):  # Check if the file exists
                    # Read the file and get the content up to <END-OF-CODE>
                    cleaned_code = read_until_end_of_code(target_file_path)

                    
                    
                    # # Define the cleaned file's output path
                    # cleaned_file_path = os.path.join(output_folder, f"{dir_id}{extn}")
                    
                    filename = f"{dir_id}{extn}"
                    cleaned_file_path = os.path.join(output_folder, filename)
                    with open(cleaned_file_path, 'w', encoding="utf-8") as file:
                        file.write(cleaned_code)  # Write the cleaned code
                    print(f"Saved cleaned file: {cleaned_file_path}")  # Debug
                else:
                    print(f"File does not exist: {target_file_path}")  # Debug

def clean_deepseek(dataset, args):
    print(f"Cleaning dataset: {dataset}, Target Language: {args.target_lang}")  # Debug

    target_lang = args.target_lang
    source_lang = args.source_lang
    EXTENSIONS = { "C": ".c", "C++": ".cpp", "Java": ".java", "Python": ".py", "Go": ".go" }
    extn = EXTENSIONS[target_lang]
    # extn = EXTENSIONS[source_lang]
    
    # Use the correct model name with the correct casing
    main_path = f"/home/codetrans/Project/data/codetlingua/{args.approach}/{dataset}/deepseek-coder-v2-lite-instruct/{source_lang}/{target_lang}/temperature_0.0"

    # main_path = f"/home/codetrans/dataset/{dataset}/{source_lang}/Code"
    
    # print(f"Main Path: {main_path}")  # Debug
    # print(f"Main Path exists: {os.path.exists(main_path)}")  # Debug

    # Function to read file up to <END-OF-CODE> and remove starting line with ```python
    def read_until_end_of_code(file_path):
        with open(file_path, 'r', encoding='utf-8') as file:
            lines = []
            recording = True
            for line in file:
                # Skip the starting line containing ```python
                if line.strip() in ('```python', '```C++', '```C', '```go'):
                    recording = True
                    continue
                elif line.strip() == '```':
                    recording = False  # Stop recording before this line
                    break  # Stop reading further
                elif line.strip() in ['END-OF-CODE', '<END-OF-CODE>']:
                    break

                if recording:
                    lines.append(line)
        return ''.join(lines)

    def read_and_clean_file(file_path):
        """Reads the file and extracts code between ```java and ```."""
        with open(file_path, 'r', encoding='utf-8') as file:
            lines = []
            recording = False  # Flag to indicate whether we are in the recording section
            code_with_comments_section = False  # Flag for detecting `####### Code with Comments #######`
            comments_section = False  # Flag for `####### Comments #######`
            code_comments_section = False
            
            buffer = []  # A buffer to store lines temporarily for multi-line detection

            for line in file:
                if line.strip() in ('```python', '```java', '```C', '```go'):
                    recording = True
                    continue                      
                     
                elif line.strip() in ('```', "Let's think step by step"):
                    recording = False  # Stop recording before this line
                    break  # Stop reading further
                    
                # Detect multi-line '####### Code with Comments #######'
                buffer.append(line.strip())
                if len(buffer) > 3:
                    buffer.pop(0)  # Keep only the last three lines in the buffer

                if buffer == ["#######", "Code with Comments", "#######"]:
                    code_with_comments_section = True  # Activate this flag after matching the three lines
                    recording = False  # Disable other recording (from ` ```java `)
                    continue  # Skip these lines and start recording after them

                if buffer == ["#######", "Code with comments", "#######"]:
                    code_comments_section = True  # Activate this flag after matching the three lines
                    recording = False  # Disable other recording (from ` ```java `)
                    continue  # Skip these lines and start recording after them
                    
                # Check for '####### Comments #######'
                if buffer == ["#######", "Comments", "#######"]:
                    comments_section = True  # Activate flag for comments
                    recording = False  # Disable other recording
                    continue  # Skip these lines and start recording after them
                    

                if recording or code_with_comments_section or comments_section or code_comments_section:
                    lines.append(line)  # Collect lines while recording

        return ''.join(lines)  # Join and return the collected lines

    # Loop through all subdirectories in the current folder path
    for dir_path in glob.glob(os.path.join(main_path, '*')):
        #print(f"Checking directory: {dir_path}")  # Debug
        if os.path.isdir(dir_path):  # Check if it's a directory
            dir_id = os.path.basename(dir_path)  # Extract folder_id as dir_id
            for hh in range(5):
                output_folder = os.path.join(main_path, str(hh))
                os.makedirs(output_folder, exist_ok=True)
                
                target_file_path = os.path.join(dir_path, f"{hh}{extn}")
                #print(f"Target file path: {target_file_path}")  # Debug

                if os.path.isfile(target_file_path):  # Check if the file exists
                    # Read the file and get the content up to <END-OF-CODE>
                    cleaned_code = read_until_end_of_code(target_file_path)

                    # cleaned_code = read_and_clean_file(target_file_path)  # Clean the file
                    
                    # # Define the cleaned file's output path
                    # cleaned_file_path = os.path.join(output_folder, f"{dir_id}{extn}")
                    
                    filename = f"{dir_id}{extn}"
                    cleaned_file_path = os.path.join(output_folder, filename)
                    with open(cleaned_file_path, 'w', encoding="utf-8") as file:
                        file.write(cleaned_code)  # Write the cleaned code
                    print(f"Saved cleaned file: {cleaned_file_path}")  # Debug
                else:
                    print(f"File does not exist: {target_file_path}")  # Debug


def clean_mistral(dataset, args):
    print(f"Cleaning dataset: {dataset}, Target Language: {args.target_lang}")  # Debug

    target_lang = args.target_lang
    source_lang = args.source_lang
    EXTENSIONS = { "C": ".c", "C++": ".cpp", "Java": ".java", "Python": ".py", "Go": ".go" }
    # extn = EXTENSIONS[target_lang]
    extn = EXTENSIONS[source_lang]
    
    # Use the correct model name with the correct casing
    # main_path = f"/home/codetrans/Project/data/codetlingua/{args.approach}/{dataset}/mistral-7b-instruct-v0.2/{source_lang}/{target_lang}/temperature_0.2"

    main_path = f"/home/codetrans/dataset/{dataset}/{source_lang}/Code"
    
    # print(f"Main Path: {main_path}")  # Debug
    # print(f"Main Path exists: {os.path.exists(main_path)}")  # Debug

    # Function to read file up to <END-OF-CODE> and remove starting line with ```python
    def read_until_end_of_code(file_path):
        with open(file_path, 'r', encoding='utf-8') as file:
            lines = []
            for line in file:
                # Skip the starting line containing ```python
                if line.strip() == '```python':
                    continue
                if '<END-OF-CODE>' in line:
                    break
                lines.append(line)
        return ''.join(lines)

    def read_and_clean_file(file_path):
        """Reads the file and extracts code between ```java and ```."""
        with open(file_path, 'r', encoding='utf-8') as file:
            lines = []
            recording = False  # Flag to indicate whether we are in the recording section
            code_with_comments_section = False  # Flag for detecting `####### Code with Comments #######`
            comments_section = False  # Flag for `####### Comments #######`
            comments = False
            
            buffer = []  # A buffer to store lines temporarily for multi-line detection

            for line in file:
                if line.strip() == '```java':
                    recording = True  # Start recording after this line
                    continue  # Skip this line                      
                     
                elif line.strip() == '```':
                    recording = False  # Stop recording before this line
                    break  # Stop reading further
                    
                # Detect multi-line '####### Code with Comments #######'
                buffer.append(line.strip())
                if len(buffer) > 3:
                    buffer.pop(0)  # Keep only the last three lines in the buffer

                if buffer == ["#######", "Code with comments", "#######"]:
                    code_with_comments_section = True  # Activate this flag after matching the three lines
                    recording = False  # Disable other recording (from ` ```java `)
                    continue  # Skip these lines and start recording after them

                if buffer == ["#######", "Code with Comments", "#######"]:
                    comments = True  # Activate this flag after matching the three lines
                    recording = False  # Disable other recording (from ` ```java `)
                    continue  # Skip these lines and start recording after them
                    
                # Check for '####### Comments #######'
                if buffer == ["#######", "Code", "#######"]:
                    comments_section = True  # Activate flag for comments
                    recording = False  # Disable other recording
                    continue  # Skip these lines and start recording after them
                    
                # # Skip '####### Code with Comments #######' and '####### Comments #######' lines
                # if line.strip() in ["#######", "Code with Comments", "Comments"]:
                #     continue
                    

                if recording or code_with_comments_section or comments_section or comments:
                    lines.append(line)  # Collect lines while recording

        return ''.join(lines)  # Join and return the collected lines

    # Loop through all subdirectories in the current folder path
    for dir_path in glob.glob(os.path.join(main_path, '*')):
        #print(f"Checking directory: {dir_path}")  # Debug
        if os.path.isdir(dir_path):  # Check if it's a directory
            dir_id = os.path.basename(dir_path)  # Extract folder_id as dir_id
            for hh in range(5):
                output_folder = os.path.join(main_path, str(hh))
                os.makedirs(output_folder, exist_ok=True)
                
                target_file_path = os.path.join(dir_path, f"{hh}{extn}")
                #print(f"Target file path: {target_file_path}")  # Debug

                if os.path.isfile(target_file_path):  # Check if the file exists
                    # # Read the file and get the content up to <END-OF-CODE>
                    # cleaned_code = read_until_end_of_code(target_file_path)

                    cleaned_code = read_and_clean_file(target_file_path)  # Clean the file
                    
                    # # Define the cleaned file's output path
                    cleaned_file_path = os.path.join(output_folder, f"{dir_id}{extn}")
                    
                    filename = f"{dir_id}{extn}"
                    cleaned_file_path = os.path.join(output_folder, filename)
                    with open(cleaned_file_path, 'w', encoding="utf-8") as file:
                        file.write(cleaned_code)  # Write the cleaned code
                    print(f"Saved cleaned file: {cleaned_file_path}")  # Debug
                else:
                    print(f"File does not exist: {target_file_path}")  # Debug


def clean_gpt_4o_mini(dataset, args):
    print(f"Cleaning dataset: {dataset}, Target Language: {args.target_lang}")  # Debug

    target_lang = args.target_lang
    source_lang = args.source_lang
    EXTENSIONS = { "C": ".c", "C++": ".cpp", "Java": ".java", "Python": ".py", "Go": ".go" }
    extn = EXTENSIONS[target_lang]
    # extn = EXTENSIONS[source_lang]
    
    # Use the correct model name with the correct casing
    main_path = f"/home/codetrans/Project/data/codetlingua/{args.approach}/{dataset}/gpt-4o-mini/{source_lang}/{target_lang}/temperature_0.0"

    # main_path = f"/home/codetrans/dataset/{dataset}/{source_lang}/Code"
    
    # print(f"Main Path: {main_path}")  # Debug
    # print(f"Main Path exists: {os.path.exists(main_path)}")  # Debug

    # Function to read file up to <END-OF-CODE> and remove starting line with ```python
    def read_until_end_of_code(file_path):
        with open(file_path, 'r', encoding='utf-8') as file:
            lines = []
            recording = False
            
            for line in file:
                # Start recording after encountering the opening marker
                if line.strip() in ('```python', '```java', '```cpp', '```c', '```go', '--- Start of Pseudocode ---'):
                    recording = True
                    continue
    
                # Stop recording upon encountering the closing marker
                if line.strip() == '```':
                    recording = False
                    break

                elif line.strip() in ['END-OF-CODE', '<END-OF-CODE>', '--- End of Pseudocode ---']:
                    break
    
                # Append lines to the result if recording is active
                if recording:
                    lines.append(line)
                
        return ''.join(lines)

    def read_and_clean_file(file_path):
        """Reads the file and extracts code between ```java and ```."""
        with open(file_path, 'r', encoding='utf-8') as file:
            lines = []
            recording = False  # Flag to indicate whether we are in the recording section
            code_with_comments_section = False  # Flag for detecting `####### Code with Comments #######`
            comments_section = False  # Flag for `####### Comments #######`
            comments = False
            
            buffer = []  # A buffer to store lines temporarily for multi-line detection

            for line in file:
                if line.strip() in ('```python', '```java'):
                    recording = True  # Start recording after this line
                    continue  # Skip this line                      
                     
                elif line.strip() == '```':
                    recording = False  # Stop recording before this line
                    break  # Stop reading further
                    
                # Detect multi-line '####### Code with Comments #######'
                buffer.append(line.strip())
                if len(buffer) > 3:
                    buffer.pop(0)  # Keep only the last three lines in the buffer

                if buffer == ["#######", "Code with comments", "#######"]:
                    code_with_comments_section = True  # Activate this flag after matching the three lines
                    recording = False  # Disable other recording (from ` ```java `)
                    continue  # Skip these lines and start recording after them

                if buffer == ["#######", "Code with Comments", "#######"]:
                    comments = True  # Activate this flag after matching the three lines
                    recording = False  # Disable other recording (from ` ```java `)
                    continue  # Skip these lines and start recording after them
                    
                # Check for '####### Comments #######'
                if buffer == ["#######", "Code", "#######"]:
                    comments_section = True  # Activate flag for comments
                    recording = False  # Disable other recording
                    continue  # Skip these lines and start recording after them
                    
                # # Skip '####### Code with Comments #######' and '####### Comments #######' lines
                # if line.strip() in ["#######", "Code with Comments", "Comments"]:
                #     continue
                    

                if recording or code_with_comments_section or comments_section or comments:
                    lines.append(line)  # Collect lines while recording

        return ''.join(lines)  # Join and return the collected lines
         
        

    # Loop through all subdirectories in the current folder path
    for dir_path in glob.glob(os.path.join(main_path, '*')):
        #print(f"Checking directory: {dir_path}")  # Debug
        if os.path.isdir(dir_path):  # Check if it's a directory
            dir_id = os.path.basename(dir_path)  # Extract folder_id as dir_id
            for hh in range(5):
                output_folder = os.path.join(main_path, str(hh))
                os.makedirs(output_folder, exist_ok=True)
                
                target_file_path = os.path.join(dir_path, f"{hh}{extn}")
                #print(f"Target file path: {target_file_path}")  # Debug

                if os.path.isfile(target_file_path):  # Check if the file exists
                    # # Read the file and get the content up to <END-OF-CODE>
                    cleaned_code = read_until_end_of_code(target_file_path)

                    # cleaned_code = read_and_clean_file(target_file_path)  # Clean the file
                    
                    # # Define the cleaned file's output path
                    cleaned_file_path = os.path.join(output_folder, f"{dir_id}{extn}")
                    
                    filename = f"{dir_id}{extn}"
                    cleaned_file_path = os.path.join(output_folder, filename)
                    with open(cleaned_file_path, 'w', encoding="utf-8") as file:
                        file.write(cleaned_code)  # Write the cleaned code
                    print(f"Saved cleaned file: {cleaned_file_path}")  # Debug
                else:
                    print(f"File does not exist: {target_file_path}")  # Debug


def main(args):
    clean_new_models(args.dataset)
    #return
    

    if args.model == 'CodeGeeX':
        clean_codegeex(args.dataset)
    elif args.model == 'CodeLlama-13b-Instruct-hf':
        clean_codellama(args.dataset, args)
    elif args.model == 'starcoder':
        clean_starcoder(args.dataset, args)
    elif args.model == 'DeepSeek-Coder-V2-Lite-Instruct':
        clean_deepseek(args.dataset, args)
    elif args.model == 'mistral-7b-instruct-v0.2':
        clean_mistral(args.dataset, args)
    elif args.model == 'gpt-4o-mini':
        clean_gpt_4o_mini(args.dataset, args)
    elif args.model == 'StarCoder':
        clean_starcoder(args.dataset, args)
    elif args.model == 'LLaMa':
        clean_llama(args.dataset)
    elif args.model == 'CodeGen':
        clean_codegen(args.dataset)
    elif args.model == 'TB-Airoboros':
        clean_airoboros(args.dataset)
    elif args.model == 'TB-Vicuna':
        clean_vicuna(args.dataset)
    elif args.model =="gpt":
        clean_gpt(args.dataset)
    elif args.model =="gpt4":
        clean_gpt4(args.dataset)


if __name__ == "__main__":

    parser = argparse.ArgumentParser(description='clean open-source model generations given a dataset and a model')
    parser.add_argument('--source_lang', help='source language to use for code translation. should be one of [Python,Java,C,C++,Go]', required=True, type=str)
    parser.add_argument('--target_lang', help='target language to use for code translation. should be one of [Python,Java,C,C++,Go]', required=True, type=str)
    parser.add_argument('--model', help='model to use for code translation.', required=True, type=str)
    # parser.add_argument('--report_dir', help='path to directory to store report', required=True, type=str)
    parser.add_argument('--approach', help='approach info', required=True, type=str)
    parser.add_argument('--dataset', help='dataset info', required=True, type=str)

    args = parser.parse_args()
    main(args)

'''
python3 /home/cse/dual/cs5190439/MTP1/codetlingua/clean_generations.py --source_lang Python --target_lang Java --model starcoder --approach autocot2d --dataset avatar
granite-20b-code-instruct
starcoder
granite-8b-code-instruct
CodeLlama-13b-Instruct-hf
'''