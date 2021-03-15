#include<sstream>

class yamada
{
    public: 
    int x;
    int y;
void function();

private:
int a=2;
    
};

void yamada::function(){
printf("%d\n",a);
}
int main()
{
    yamada kk;
    kk.x=60;
    kk.y=7;
printf("%d\n%d",kk.x,kk.y);
kk.function();
    
    return 0;
}

