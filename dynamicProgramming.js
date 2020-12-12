//dynamic programming, fibonacci

const fib = (n, memo = {}) => {
    if(n<=0)
        return 0;
    else if(n===1 || n===2)
        return 1;
    else if(n in memo)
        return memo[n];    
    else{
        memo[n] = fib(n-1,memo) + fib(n-2, memo);
    }        
    return memo[n];
}

console.log(fib(6));

////////////////////////////////////////////////


