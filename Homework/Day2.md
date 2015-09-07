### Exercise 1..1
---


##### 1.
```
let x be a stack

foreach line in file
      x.push(line)

while x is not empty
      print x.pop()
```

##### 2.
```
let x be a stack

while file has next line
      while size of x is less than 50 and file has next line
            x.push(line)

      while x is not empty
            print x.pop()

```

##### 3.
```
let x be a FIFO Queue

while file has next line
      x.add(line)

      if size of x is greater than or equal to 43
            let LastLine be x.remove()
            if line is empty
                    print LastLine
```

##### 4.
```
let x be a USet

foreach line in file
      if x.add(line)
            print line
```

##### 5.
```
let x be a USet

foreach line in file
      if x.add(line) is false
            print line
```
##### 6.

I was slightly confused on how the compare function worked. From the reading I assumed it would return 0 if the new elem was the same as one already in the set and would then not add the new elem. It would return a negative if the new elem belonged further in the set than x and finally it would return a positive if it belonged earlier in the set than x.
```
let x be a SSet

let x.compare(x,y) be
      if x is y
            return 0

      let size be x.size - y.size
      if size is not 0
            return size
      else
            return -1

foreach line in file
      x.add(line)

for i from 0 to x.size()
    print elemnt i of x

clear x      
```

##### 7.

```
let x be a SSet

let x.compare(x,y) be
      let size be x.size - y.size
      if size is not 0
            return size
      else
            return -1

foreach line in file
      x.add(line)

for i from 0 to x.size()
    print elemnt i of x

clear x  
```

##### 8.

```
let x be a FIFO Queue
let y be a FIFO Queue

let even be TRUE
while file has next line
      if even
            x.add(line)
      else
            y.add(line)
      even = not even

for i from 0 to x.size()
      print element i of x

clear x

for i from 0 to y.size()
      print element i of y

clear y
```

##### 9.

```
let x be an ArrayList

while file has next line
      x.add(line)

while x is not empty
      let i be a random number from 0 to x.size
      print x.remove(i)
```

### Exercise 1..2
---
Here I assume the Dyck word is being given as an array of integers
```
bool isThisADyckWord(int[] DyckWord)

let x be a Stack

for i from 0 to DyckWord.Length
      if DyckWord[i] is 1
            x.push(1)
      else if x.size > 0
            x.pop()
      else
            return false

return true
```
