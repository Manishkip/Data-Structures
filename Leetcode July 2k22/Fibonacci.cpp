class Solution {
public:
    int fib(int n) {
        if(n == 0 || n == 1) // it is base condition, if n is zero or one
            return n; // then return 1
        
        return fib(n - 1) + fib(n - 2); // return what it wants
    }
};
