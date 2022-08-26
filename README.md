# 42-push_swap

This project is about sorting some set of numbers using only 2 stacks and some strict rules.

## Rules

- **`sa`** : **swap a** - Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements).
- **`sb`** : **swap b** - Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements).
- **`ss`** : **`sa`** and **`sb`** at the same time.
- **`pa`** : **push a** - take the first element at the top of b and put it at the top of a. Do nothing if B is empty.
- **`pb`** : **push b** - take the first element at the top of a and put it at the top of b. Do nothing if A is empty.
- **`ra`** : **rotate a** - shift up all elements of stack A by 1. The first element becomes the last one.
- **`rb`** : **rotate b** - shift up all elements of stack B by 1. The first element becomes the last one.
- **`rr`** : **`ra`** and **`rb`** at the same time.
- **`rra`** : **reverse rotate a** - shift down all elements of stack A by 1. The last element becomes the first one.
- **`rrb`** : **reverse rotate b** - shift down all elements of stack B by 1. The last element becomes the first one.
- **`rrr`** : **`rra`** and **`rrb`** at the same time.

## The Algorithm

I used different algorithms for different size of stacks.

For 5 or fewer numbers I'm pushing the smallest numbers to stack b until stack a has only 3 numbers. With 3 numbers on stack a, there are only 6 different variations of arrangements. I'm making the moves for the right arrangement. On stack b, I'm just pushing the numbers to stack a in correct order, and the whole stack a is now sorted.

For more than 5 numbers I'm dividing the stack by a certain number. This number changes depending on the size of the set of numbers. For example, for 100 numbers I'm dividing the stack into 3 sections. I'm starting with the largest numbers and I'm pushing them to stack b until only 2/3 of the numbers are left on stack a. Then on stack b I identify both the smallest and biggest number on that stack and I calculate their moves for pushing them to stack a. Whichever has the lower moves I'm executing its moves. I'm making this until stack b is completely empty. Then again I'm pushing 1/3 of the numbers to stack b. This time it's the medium values. And again I'm doing the same thing in stack b and so on. After I pushed everything to stack b and again I pushed them to stack a, and all the numbers are now ordered.

Visual representation of 100 numbers sorting:

![100 number sorting visually](https://user-images.githubusercontent.com/61047851/186911186-b35d29d0-7613-4f0e-9bff-2074e92a042c.gif)
