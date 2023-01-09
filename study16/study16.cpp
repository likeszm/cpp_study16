/*
* 名称: 文件和流测试
* 
* 收获:
* 1、fstream中有 ifstream（读） 和 ofstream（写） 两个类,fstream类既可以读也可以写
* 2、文件本身就是一个对象
* 3、读写各有一个指针,和单片机里读写寄存器类似
*/

#include <iostream>

#include <fstream>

void read_file_test(void);
void write_file_test(void);
void R_and_W_test(void);


int main()
{
    //write_file_test();
    //read_file_test();
    //R_and_W_test();


    std::cout << "\n测试完成\n";
    return 0;
}

void read_file_test(void)
{
    std::ifstream test_file;        //文件是一个对象,input file限定了只读
    test_file.open("测试文件.txt");     //第二个参数不填,默认只读模式打开

    char buffer[100];      //缓冲区

    for (int i = 0; i < 3; i++)
    {
        test_file >> buffer;            // >>(char)data[]运算符重载成了输出,遇到回车就输出,和cin是一样的 

        std::cout << "\n第" << i + 1 << "行内容是: " << std::endl;
        std::cout << buffer;            
    }



    //for (int i = 0; i < 100; i++)
    //{
    //    std::cout << "buffer[" << i << "] = >" << buffer[i] << "<" << std::endl;
    //}


    test_file.close();                              //打开和关闭必须对应
}

void write_file_test(void)
{
    std::ofstream test_file;
    test_file.open("测试文件.txt");     
    //因为是outout file对象,默认写模式打开,但是会覆盖以前的内容!!!

    char buffer[100];

    for (int i = 1; i < 3; i++)
    {
        std::cout << "输入第" << i << "行内容:" << std::endl;
        std::cin >> buffer; 
 //       std::cin.ignore();      
        test_file << buffer;
        test_file << '\n';      //不会自动写入换行!
    }

 //    test_file >> buffer;   //不允许读取

    test_file.close();
}

void R_and_W_test(void)
{
    std::fstream test_file;
    //test_file.open("测试文件.txt",std::ios::in | std::ios::out);
    test_file.open("测试文件.txt");
    char buffer[100] = "测试数据";
    test_file.seekp(2);          //put,写入指针
    test_file << buffer;
    std::cout << "读取:" << std::endl;
    test_file.seekg(0);         //读取指针指向第0个字符位置
    char temp[100];
    test_file >> temp;
    std::cout << temp;

    test_file.close();
}

