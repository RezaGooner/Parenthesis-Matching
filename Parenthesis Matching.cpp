#include <iostream>
#include <string>

using namespace std ;

const int MAX_SIZE = 100; 


struct Stack {
    int top; // index of top of stack
    string elements[MAX_SIZE]; 
};

bool isEmpty(Stack& stack) {
    if (stack.top == -1){
        return true ;
    }
    return false ;
}

bool isFull(Stack& stack) {
    if (stack.top == MAX_SIZE - 1){
        return true ;
    }
    return false ;
}

void push(Stack& stack, string value) {
    if (isFull(stack)) {
        cout << "Stack overflow!" << endl;
        return;
    }
    stack.elements[++stack.top] = value ;
}

void pop(Stack& stack) {
    if (isEmpty(stack)) {
        cout << "Stack underflow!" << endl;
        return;
    }
    stack.elements[stack.top--] = "" ;
}

string top(Stack& stack) {
    if (isEmpty(stack)) {
        //cout << "Stack is empty!" << endl;
        return "";
    }
    return stack.elements[stack.top];
}

bool parenthesisMatching(Stack& stack , string phrase){
    for (int i = 0 ; i < phrase.size() ; i++){
        if (phrase[i] != '{' && phrase[i] != '}' && phrase[i] != '(' && phrase[i] != ')' && phrase[i] != '[' && phrase[i] != ']'){
            continue ;
        }
        switch (phrase[i]) {
            case ')' :
                if (top(stack) == "(" ){
                    pop(stack);
                } 
                else {
                    push(stack , string(1, phrase[i]));
				}
                break ;

            case ']' :
                if (top(stack) == "[" ){
                    pop(stack);
                }
                else {
                    push(stack , string(1, phrase[i]));
				}
                break ;

            case '}' :
                if (top(stack) == "{" ){
                    pop(stack);
                }
                else {
                    push(stack , string(1, phrase[i]));
				}
                break ;

            default :
                push(stack , string(1, phrase[i]));
        }
    }
    if (isEmpty(stack)){
        return true ;
    }
    return false ;
}

int main() {
    Stack stack;
    stack.top = -1; 
    string str ;
    cout << "Enter the phrase : " ;
    cin >> str ;
    if (parenthesisMatching(stack , str )){
    	cout << "True" ;
	} else {
		cout << "False" ;
	}

    return 0;
}