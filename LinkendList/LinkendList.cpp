#include <iostream>

using namespace std;

//template <typename T>
//class MyArray
//{
//    T* arr;
//    int _n;
//
//    public:
//        class Iterator;
//
//        MyArray(int n = 1) : _n(n), arr(new T[n]) {}
//
//
//        T& operator[] (const int& n)
//        {
//            if (n > 0 && n < _n)
//                return arr[n];
//            return arr[0];
//        }
//
//        Iterator begin() { return arr; }
//        Iterator end() { return arr + _n; }
//
//        friend ostream& operator<< (ostream& s, const MyArray<T>& n);
//
//        class Iterator
//        {
//            T* cur;
//
//            public: 
//                Iterator(T* first) : cur(first)
//                {}
//                T& operator+ (int n) { return *(cur + n); }
//                T& operator- (int n) { return *(cur - n); }
//
//                T& operator++ (int) { return *cur++; }
//                T& operator-- (int) { return *cur--; }
//                T& operator++ () { return *++cur; }
//                T& operator-- () { return *--cur; }
//
//                bool operator!= (const Iterator& it) { return cur != it.cur; }
//                bool operator== (const Iterator& it) { return cur == it.cur; }
//                T& operator* () { return *cur; }
//        };
//};
//
//template <typename T>
//ostream& operator<< (ostream& s, const MyArray<T>& n)
//{
//    s << MyArray<T>::arr[n];
//    return s;
//}

class Node
{
    public:
        int index;
        int value;
        Node* forward;
        Node* back;

        Node(int value) : index(value) { }

        Node(int value, int index) {
            this->index = index;
            this->value = value;
        }

        Node(int value, int index, Node* back) {
            this->index = index;
            this->value = value;
            this->back = back;
        }

        Node(int value, int index, Node* back, Node* forward) {
            this->index = index;
            this->value = value;
            this->back = back;
            this->forward = forward;
        }

};

class LinkedList
{
    public:
        Node* root;

        LinkedList(int rootValue)
        {   
            root = new Node(rootValue, 0, nullptr, nullptr);
            //root->value = rootValue;
            //root->index = 0;
            //root->back = nullptr;
            //root->forward = nullptr;
        }

        int GetValueByIndex(int index)
        {
            Node* temp = root;

            while (temp->index != index)
                temp = temp->forward;

            return temp->value;
        }

        void Add(int value)
        {
            Node* temp = root;

            while (temp->forward != nullptr)
                temp = temp->forward;

            temp->forward = new Node(value, temp->index + 1, temp);
        }

        void AddAtIndex(int value, int index)
        {
            //Node* temp = root;

            //while (temp->index != index)
            //    temp = temp->forward;

            //temp->back = new Node(value, index, temp->back->back, temp);

            Node* temp = root;

            while (temp->index != index)
                temp = temp->forward;

            Node* nodeToAdd = new Node(value, index, temp->back, temp);            

            temp->back->forward = nodeToAdd;
            temp->back = nodeToAdd;


            RestoreIndecies(temp->back);
        }

        void Remove(int value)
        {
            Node* temp = root;

            while (temp->value != value)
                temp = temp->forward;

            temp->back->forward = temp->forward;
            temp->forward->back = temp->back;
            delete temp;

            temp = root;

            RestoreIndecies(temp);
        }

        void RestoreIndecies(Node* temp)
        {
            while (temp->forward != nullptr)
            {
                temp = temp->forward;
                temp->index = temp->back->index + 1;
            }
        }

        //class Iterator
        //{
        //    T* cur;

        //public:
        //    Iterator(T* first) : cur(first)
        //    {}
        //    T& operator+ (int n) { return *(cur + n); }
        //    T& operator- (int n) { return *(cur - n); }

        //    T& operator++ (int) { return *cur++; }
        //    T& operator-- (int) { return *cur--; }
        //    T& operator++ () { return *++cur; }
        //    T& operator-- () { return *--cur; }

        //    bool operator!= (const Iterator& it) { return cur != it.cur; }
        //    bool operator== (const Iterator& it) { return cur == it.cur; }
        //    T& operator* () { return *cur; }
        //};
};

int main()
{
    LinkedList* list = new LinkedList(123);
    list->Add(11);
    list->Add(222);
    list->Add(3333);
    list->Add(44444);
    list->Add(555555);
    list->AddAtIndex(777, 2);
    //list->Remove(22);

    std::cout << list->GetValueByIndex(3);
}

//MyArray<int> arr(3);

//int a = 0;

//arr[a] = 5;
//arr[1] = 6;
//arr[2] = 7;

//int& al = a;

//int* ap = &a;
//*ap;

//cout << arr[2] << endl;

    //arr[0] = "str1";
    //arr[1] = "str2";
    //arr[2] = "str3";

    //auto it = MyArray<char*>::Iterator(arr.begin());
    //cout << "2: " << it + 2 << endl;

    //while (it != arr.end())
    //{
    //    cout << *it << endl;
    //    it++;
    //}