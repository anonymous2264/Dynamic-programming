class Solution {
public:
    bool isPalindrome(int x) {
        long long int d,c=0;
        long long int temp=x;
        if(x<0)
        return false;
        while(x)
        {
            d=x%10;
            c=d+(c*10);
            x=x/10;
    }
    if(c==temp)
    return true;
    else 
    return false;
    }
};