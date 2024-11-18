#include <iostream>
#include <string>
#include <memory>

struct Node {
    char item;
    std::shared_ptr<Node> next;
};

using StackNode = std::shared_ptr<Node>;

struct Stack {
    StackNode top;
};

void StackInitialize(Stack* s) {
    s->top = nullptr;
}

bool StackEmpty(const Stack& s) {
    return (s.top == nullptr);
}

void Push(Stack* s, char c) {
    StackNode p = std::make_shared<Node>();
    p->item = c;
    p->next = s->top;
    s->top = p;
}

char Pop(Stack* s) {
    StackNode p = s->top;
    s->top = s->top->next;
    return p->item;
}

int main() {
    std::string st;
    Stack s;
    StackInitialize(&s);
    
    std::cout << "Nhap vao xau ky tu: ";
    std::getline(std::cin, st);
    
    for (size_t i = 0; i < st.length(); i++) {
        Push(&s, st[i]);
    }
    
    std::cout << "Xau da dao nguoc: \n";
    while (!StackEmpty(s)) {
        std::cout << Pop(&s);
    }
    
    return 0;
}

