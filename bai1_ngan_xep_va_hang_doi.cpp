#include <iostream>
#include <stack>
#include <string>
using namespace std;

class StackInt {
private:
    static const int max = 100;
    int arr[max];
    int top;
public:
    StackInt() {
        top = -1;
    }

    bool IsEmpty() {
        return top == -1;
    }

    bool IsFull() {
        return top == max - 1;
    }

    void PushStack(int x) {
        if (IsFull()) {
            cout << "Stack day!\n";
            return;
        }
        arr[++top] = x;
    }

    int PopStack() {
        if (IsEmpty()) {
            cout << "Stack rong!\n";
            return -1;
        }
        return arr[top--];
    }

    int PeekStack() {
        return IsEmpty() ? -1 : arr[top];
    }

    void Clear() {
        top = -1;
    }
};

// Stack dung danh sach lien ket
struct Node {
    int data;
    Node* next;
};

class LinkedStackInt {
private:
    Node* top;
public:
    LinkedStackInt() {
        top = NULL;
    }

    bool IsEmpty() {
        return top == NULL;
    }

    void PushStack(int x) {
        Node* temp = new Node{x, top};
        top = temp;
    }

    int PopStack() {
        if (IsEmpty()) {
            cout << "Stack rong!\n";
            return -1;
        }
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    int PeekStack() {
        return IsEmpty() ? -1 : top->data;
    }

    void Clear() {
        while (!IsEmpty()) PopStack();
    }
};

// Ung dung dao so
void dao_so() {
    StackInt s;
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    cout << "Nhap cac so: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.PushStack(x);
    }
    cout << "Day so dao nguoc: ";
    while (!s.IsEmpty()) {
        cout << s.PopStack() << " ";
    }
    cout << endl;
}

// Kiem tra xau doi xung
bool xau_doi_xung(const string& str) {
    stack<char> s;
    for (char c : str) s.push(c);
    for (char c : str) {
        if (c != s.top()) return false;
        s.pop();
    }
    return true;
}

// Chuyen doi so thap phan sang nhi phan
string thap_phan_sang_nhi_phan(int n) {
    StackInt s;
    while (n > 0) {
        s.PushStack(n % 2);
        n /= 2;
    }
    string result = "";
    while (!s.IsEmpty()) result += to_string(s.PopStack());
    return result;
}

// Chuyen bieu thuc trung to sang hau to
int Priority(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

string InfixToPostfix(string exp) {
    stack<char> s;
    string result = "";
    for (char c : exp) {
        if (isalnum(c)) result += c;
        else if (c == '(') s.push(c);
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                result += s.top();
                s.pop();
            }
            s.pop();
        } else {
            while (!s.empty() && Priority(s.top()) >= Priority(c)) {
                result += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    while (!s.empty()) {
        result += s.top();
        s.pop();
    }
    return result;
}

// Danh gia bieu thuc hau to
int EvaluatePostfix(string exp) {
    stack<int> s;
    for (char c : exp) {
        if (isdigit(c)) s.push(c - '0');
        else {
            if (s.size() < 2) {
                cout << "Loi bieu thuc!\n";
                return -1;
            }
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            switch (c) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/':
                    if (b == 0) {
                        cout << "Loi: chia cho 0!\n";
                        return -1;
                    }
                    s.push(a / b);
                    break;
            }
        }
    }
    return s.top();
}

int main() {
    cout << "Dao so: ";
    dao_so();

    string str;
    cout << "Nhap chuoi kiem tra doi xung: ";
    cin >> str;
    cout << (xau_doi_xung(str) ? "Chuoi doi xung" : "Khong doi xung") << endl;

    int num;
    cout << "Nhap so thap phan: ";
    cin >> num;
    cout << "Dang nhi phan: " << thap_phan_sang_nhi_phan(num) << endl;

    string expr;
    cout << "Nhap bieu thuc trung to: ";
    cin >> expr;
    string postfix = InfixToPostfix(expr);
    cout << "Bieu thuc hau to: " << postfix << endl;
    cout << "Gia tri bieu thuc: " << EvaluatePostfix(postfix) << endl;

    return 0;
}
