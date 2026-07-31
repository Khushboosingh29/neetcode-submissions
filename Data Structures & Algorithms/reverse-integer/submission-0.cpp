class Solution {
public:
    int reverse(int x) {
        int max=2147483647;
        int min=-2147483648;
        int res=0;
        while( x!=0){
            int dig=x%10;
            x=x/10;
            if(res>max/10 || (res==max/10  && dig>max%10))
                return 0;
             if(res<min/10 || (res==min/10  && dig<min%10))
                return 0;
            res=(res*10)+dig;
        }
        return res;
        
    }
};
