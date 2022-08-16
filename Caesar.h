#include<iostream>
#include<fstream>

class Caesar {
    public:
        Caesar();
        ~Caesar();
    public:
        void setKey(int);
        int getKey() const;
        void encrypt();
        void decrypt();
    private:
        int m_key;
        std::fstream fin;
        std::fstream fout;
};