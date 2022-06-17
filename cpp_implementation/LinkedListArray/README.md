# LinkedList implementation using array

Here we discuss about implementation LinkedList using array.

The main idea that's we use array and create a wrapper class LinkedList.

Let's see the idea of list by realization of it interface:
1. insert item
2. delete item

Before we start assume that we initialize our list like this:

and it have next properties:
1. array to contain elements
2. current_size to show how mane elements our linkedlist contains


### Inserting an item

Assume that we have two methods for inserting items:
1. push_back(elem) -- adding item at the end of out list
2. insert_at(elem, index) -- adding item at specific index with moving rest of elements

At start our lists look like this.

And we calling push_back methods:
1. push_back(1);
2. push_back(2);
3. push_back(3);

Our lists we look like this:

![alt text](img/start.png?raw=true)

Having `current_size` we can fast add new elements in our lists (complexety O(1)) at the end 

```
array[current_size] = elem
current_size++;
```

![alt text](img/push_back.png?raw=true)

Let's see how will work `insert_at(elem, index)`. 
Our list:

We calling methods:
1. insert_at(4,0);
2. insert_at(6, 2);

First we check i we have enough space for new insert. If so then we move elements starting by index to the end of list by 1 position.

Commands will execute like this:

![alt text](img/insert_at_one.png?raw=true)

![alt text](img/insert_at.png?raw=true)


So what's the advantages of this realization:
1. We can fact access elements by position
2. No needle for memory handle

Disadvantages:
1. List size is limited
2. Insert elemnt at position makes rest of elements move (0(n))
3. Arrray should be initialized by start value
