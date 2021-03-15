#include<sstream>

// void main(void)
// {
//     Try
//     {
//         int p;
//         p = 3;
//     }
//     Catch(p == 3)
//     {
        
//     }
// }
class ig
{
    public:
        int a,b; 
        void kansu();   
    private:
        int c = 7;
       
};

void ig::kansu()
{
    printf("%d\n", c);
}

int main()
{
    ig inoguchi;
    inoguchi.a = 3;
    inoguchi.b = 5;
    
    inoguchi.kansu();
}