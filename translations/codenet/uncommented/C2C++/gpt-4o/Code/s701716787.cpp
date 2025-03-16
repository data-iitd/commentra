#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#define COMMAND_LENGTH (10)   /* Command length */

class ST_NODE {
public:
    ST_NODE* st_parent;
    ST_NODE* st_left;
    ST_NODE* st_right;
    int s4_key;

    ST_NODE(int key) : st_parent(nullptr), st_left(nullptr), st_right(nullptr), s4_key(key) {}
};

void vd_d_insert(ST_NODE** st_ap2_root, int s4_a_key);
void vd_d_print(ST_NODE* st_ap_root);
static void vd_s_printPreOrder(ST_NODE* st_ap_node);
static void vd_s_printInOrder(ST_NODE* st_ap_node);

int main() {
    ST_NODE* st_tp_root = nullptr;
    int s4_t_numCommand;
    int s4_t_iCommand;
    char s1_tp_command[COMMAND_LENGTH];
    int s4_t_insertKey;

    // Number of commands
    std::cin >> s4_t_numCommand;

    // Execute commands
    for (s4_t_iCommand = 0; s4_t_iCommand < s4_t_numCommand; s4_t_iCommand++) {
        std::cin >> s1_tp_command;

        // Command execution
        if (strcmp(s1_tp_command, "insert") == 0) {
            // If insert, get the key value
            std::cin >> s4_t_insertKey;
            vd_d_insert(&st_tp_root, s4_t_insertKey);
        } else {
            vd_d_print(st_tp_root);
        }
    }

    return 0;
}

void vd_d_insert(ST_NODE** st_ap2_root, int s4_a_key) {
    ST_NODE* st_tp_parentNode = nullptr;
    ST_NODE* st_tp_indexNode = *st_ap2_root;
    ST_NODE* st_tp_insertNode = new ST_NODE(s4_a_key);

    while (st_tp_indexNode != nullptr) {
        st_tp_parentNode = st_tp_indexNode;
        if (st_tp_insertNode->s4_key < st_tp_indexNode->s4_key) {
            st_tp_indexNode = st_tp_indexNode->st_left;
        } else {
            st_tp_indexNode = st_tp_indexNode->st_right;
        }
    }
    st_tp_insertNode->st_parent = st_tp_parentNode;

    if (st_tp_parentNode == nullptr) {
        *st_ap2_root = st_tp_insertNode;
    } else if (s4_a_key < st_tp_parentNode->s4_key) {
        st_tp_parentNode->st_left = st_tp_insertNode;
    } else {
        st_tp_parentNode->st_right = st_tp_insertNode;
    }
}

void vd_d_print(ST_NODE* st_ap_root) {
    vd_s_printInOrder(st_ap_root);
    std::cout << std::endl;
    vd_s_printPreOrder(st_ap_root);
    std::cout << std::endl;
}

static void vd_s_printPreOrder(ST_NODE* st_ap_node) {
    if (st_ap_node == nullptr) {
        return;
    }

    std::cout << " " << st_ap_node->s4_key;
    vd_s_printPreOrder(st_ap_node->st_left);
    vd_s_printPreOrder(st_ap_node->st_right);
}

static void vd_s_printInOrder(ST_NODE* st_ap_node) {
    if (st_ap_node == nullptr) {
        return;
    }

    vd_s_printInOrder(st_ap_node->st_left);
    std::cout << " " << st_ap_node->s4_key;
    vd_s_printInOrder(st_ap_node->st_right);
}

// No need for a separate constructor function in C++
