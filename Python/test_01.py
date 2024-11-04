# Take the task input from the user
task = input()

if task == 'permutation':
    # Task 1: Permutation
    s = input()
    # Generate and print all two-letter permutations without repetition
    for i in range(len(s)):
        for j in range(len(s)):
            if i != j:  # Ensure no repetition of the same letter
                print(s[i] + s[j])

elif task == 'sorted_permutation':
    # Task 2: Sorted Permutation
    s = input()
    # Generate all two-letter permutations where the first comes before the second
    for i in range(len(s)):
        for j in range(len(s)):
            if i != j and s[i] < s[j]:  # Ensure no repetition and alphabetical order
                print(s[i] + s[j])

elif task == 'repeat_the_repeat':
    # Task 3: Repeat the Repeat
    n = int(input())
    # Print numbers 1 to n on the same line, repeated n times
    for i in range(n):
        for j in range(1, n + 1):
            print(j, end="")
        print()

elif task == 'repeat_incrementally':
    # Task 4: Repeat Incrementally
    n = int(input())
    # Print the incremental pattern
    for i in range(1, n + 1):
        for j in range(1, i + 1):
            print(j, end="")
        print()

elif task == 'increment_and_decrement':
    # Task 5: Increment and Decrement
    n = int(input())
    # Print the pattern where k-th line contains numbers from 1 to k and back down to 1
    for i in range(1, n + 1):
        # Increment part (1 to i)
        for j in range(1, i + 1):
            print(j, end="")
        # Decrement part (i-1 to 1)
        for j in range(i - 1, 0, -1):
            print(j, end="")
        print()

else:
    print("Invalid task")
