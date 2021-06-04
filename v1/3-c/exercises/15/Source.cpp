#include <iostream>

typedef struct Structure {
    std::string s1;
    std::string s2;
    int i;
} MyStruct;

int main() {
    MyStruct st;
    st.s1 = "S1";
    st.s1 = "S2";
    st.i = 3;

    MyStruct* struct_address = &st;

    std::cout << "Initial structure:\n"
        << "s1 = " << st.s1
        << "\ns2 = " << st.s2
        << "\ni = " << st.i
        << "\nAddress = " << struct_address << std::endl;

    struct_address->s1 = "Modified S1";
    struct_address->s2 = "Modified S2";
    struct_address->i = 7;

    std::cout << "Modified structure:\n"
        << "s1 = " << st.s1
        << "\ns2 = " << st.s2
        << "\ni = " << st.i
        << "\nAddress = " << struct_address << std::endl;
}