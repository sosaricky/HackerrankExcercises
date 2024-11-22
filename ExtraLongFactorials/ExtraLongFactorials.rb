# Level : Medium
# Author : RaulSosa
# Status : Solved

# Note : This algorithm is pretty simple but the trick is take advantange from BigIntegers in ruby
def extraLongFactorials(n)
    # factorial(n) = n*(n-1)(n-2)...3*2*1
      productory = n
      while(n>=2) do
          productory *=(n-1)
          n -=1
      end
    return productory
  end

# Example
puts extraLongFactorials(5)
