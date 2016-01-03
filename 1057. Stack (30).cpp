# include <cstdio>
# include <stack>
# include <set>
using namespace std;
 typedef int T;
 
class MyClass   //implement PeekMedian function
{
public:
    int PeekMedian();       //return the midian value (n/2)th when n is even
                            //else ((n+1)/2)th if n is odd
    int Pop();
    void Push(int);
    bool invalid();
    void Erase(T);
private:
    stack<int> st;
    multiset<T, greater<T>> maxHeap;
    multiset<T, less<T>> minHeap;
 
};
void MyClass::Erase(T data)
{
    multiset<T>::iterator it;
    if ((it = maxHeap.find(data)) != maxHeap.end())
        maxHeap.erase(it);
    else if ((it = minHeap.find(data)) != minHeap.end())
        minHeap.erase(it);
}
bool MyClass::invalid()
{
    return st.empty();
}
int MyClass::PeekMedian()
{
    //get
    if (invalid())
        return 1000001; //invalid
 
    while (minHeap.size() < maxHeap.size())
    {
        minHeap.insert(*maxHeap.begin());
        maxHeap.erase(maxHeap.begin());
    }
    while (maxHeap.size() < minHeap.size())
    {
        maxHeap.insert(*minHeap.begin());
        minHeap.erase(minHeap.begin());
    }
    multiset<T>::iterator min = maxHeap.begin();
    multiset<T>::iterator max = minHeap.begin();
    if (min == maxHeap.end()) return *minHeap.begin();
    if (max == minHeap.end()) return *maxHeap.begin();
    while (*min>*max)
    {
        minHeap.insert(*min);
        maxHeap.insert(*max);
        minHeap.erase(max);
        maxHeap.erase(min);
        min = maxHeap.begin();
        max = minHeap.begin();
    }
    return *min;
}
int MyClass::Pop()
{
    if (invalid())
        return 1000001; //invalid
    int n = st.top();
    st.pop();
    Erase(n);
    return n;
}
void MyClass::Push(int n)
{
    st.push(n);
    if (maxHeap.size() == minHeap.size()) {
        maxHeap.insert(n);
    }else {
        minHeap.insert(n);
    }
}
MyClass FM;
 
int main()
{
    int n, tmp,reValue;
    bool ctrl = true;
    scanf("%d", &n);
     
    char str[10];
    while (n--)
    {
            if (ctrl)
                ctrl = false;
            else
                printf("\n");;
        scanf("%s", str);
        switch (str[1])
        {
        case 'e':
        {
            reValue=FM.PeekMedian();
            if (reValue == 1000001)
                printf("Invalid");
            else
                printf("%d", reValue);
            break;
        }
        case 'o':
        {
            reValue = FM.Pop();
            if (reValue == 1000001)
                printf("Invalid");
            else
                printf("%d", reValue);
            break;
        }
        case 'u':
        {
            scanf("%d", &tmp);
            FM.Push(tmp);
            ctrl = true;
        }
        break;
        }
    }
    return 0;
}