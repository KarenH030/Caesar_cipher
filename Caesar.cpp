#include"Caesar.h"

#include<string>

Caesar::Caesar(){

    std::string path1 = "encrypt.txt";
    std::string path2 = "decrypt.txt";
    fin.open(path1);
    fout.open(path2);
    if (fin.is_open() && fout.is_open()){
        std::cout << "File is open!" << std::endl;
    }
    else {
        std::cout << "ERORR!!!" << std::endl;
    }  

}

void Caesar::setKey(int key) {
    m_key = key; 
}

int Caesar::getKey () const {
    return m_key;
}
Caesar::~Caesar() {
    fin.close();
    fout.close();
}

void Caesar::encrypt () {
    std::string str = "";
    while (!fin.eof()) {    
        std::string tmp = "";
        std::getline(fin,tmp);
        for (int i = 0; i < tmp.size(); ++i) 
        {
             if (tmp[i] >= 'A' && tmp[i] <= 'Z') 
             {
                if ((tmp[i] - m_key) < 'A') 
                {
                    str += char((tmp[i] - m_key) + 26);
                } 
                else 
                {
                    str += char(tmp[i] - m_key);
                }
             } 
             else if (tmp[i] >= 'a' && tmp[i] <= 'z') 
             {
                if (tmp[i] - m_key < 'a') 
                {
                    str += char((tmp[i] - m_key) + 26);
                } 
                else 
                {
                    str += char(tmp[i] - m_key);
                }
             }
             else
             {
                str += char(tmp[i]);
             }
             fout << str;
             str = "";
        }

    }
}



void Caesar::decrypt () {
    std::string str = "";
    while (!fout.eof()) {    
        std::string tmp = "";
        std::getline(fout,tmp);
        for (int i = 0; i < tmp.size(); ++i) 
        {
             if (tmp[i] >= 'A' && tmp[i] <= 'Z') 
             {
                if ((tmp[i] - m_key) > 'Z') 
                {
                    str += char((tmp[i] + m_key) - 26);
                } 
                else 
                {
                    str += char(tmp[i] - m_key);
                }
             } 
             else if (tmp[i] >= 'a' && tmp[i]<= 'z') 
             {
                if (tmp[i] - m_key < 'z') 
                {
                    str += char((tmp[i] + m_key) - 26);
                } 
                else 
                {
                    str += char(tmp[i] + m_key);
                }
             }
             else
             {
                str += char(tmp[i]);
             }
             fin << str;
             str = "";
        }

    }
}

int main(){
    
}
