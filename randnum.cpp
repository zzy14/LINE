#include   "RandNum.h"  
#ifndef    INCLUDE_ALGORITHM  
#define    INCLUDE_ALGORITHM  
#include   <algorithm>  
#endif  
#define    LENGTH 100000000  
RandNum::RandNum(time_t* init /* =NULL */)  
{   
    srand(time(init)); // set the seed;  
}  
RandNum::~RandNum(){};  
int RandNum::Rand(int N)  
{// the basic random number generate funcion  
    int BOUND=RAND_MAX-(RAND_MAX%N); // BOUND = k*N 是N的整数倍  
    int re=rand();  
    while(re>BOUND) // 如果大于BOUND那么重新生成随机数  
        re=rand();  
    return re%N;  
}  
long RandNum::randTemp(int exp)  
{  
    long re=0;  
    while(exp>=4) //这里的4也可以换为其他的数字，但不要使得10^exp超过RAND_MAX就好，太小的话可能会有点慢
    {  
        re*=pow(10,4);  
        re+=Rand(10000);  
        exp-=4;  
    }  
    re=re*(pow(10,exp))+Rand(pow(10,exp)); // 最后一个可能是0,1,2,3而不一定是4，所以需要特殊处理使得服从密度为1/pow(10,exp)的均匀分布;  
    return re;  
}  
long RandNum::randLong(long upBound)  
{  
    int mtg=ceil(log10(upBound*1.0));   
    long suN=pow(10,mtg);   // 简单地计算其上界  
    long BOUND=suN-(suN%upBound);  
    long re=randTemp(mtg);         
    //-------------------------类似于myrand()中的处理  
    while(re>BOUND)  
         re=randTemp(mtg);  
    return re%upBound;  
}  
