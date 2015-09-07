### Exercise 2..1

The amortized cost of the add(i, x) function is O(n-i). This means an add_all(i, c), where c is a collection and repeated calls to add(i, x) are made, would have a cost of O(c.length * (n-i)). A much more efficient method exists.

```
add_all(i, c)                                             Cost              Times Executed
      b = new array(2*(n + c.length))                     O(n+c.length)     O(1)
      for j = 0 to i-1
          b[j] = a[j]                                     O(1)              O(i)
      for j = i to i + c.length - 1
          b[j] = c[j-i]                                   O(1)              O(c.length)  
      for j = i + c.length to c.length + n - 1
          b[j] = a[j-c.length]                            O(1)              O(n-i)
      a = b
      n += c.length
```
and we see that this method has a cost of O(n+c.length)
