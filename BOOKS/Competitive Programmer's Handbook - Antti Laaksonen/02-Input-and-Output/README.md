## Input and Output

The functions `cin` and `cout` can be heavy depending on the problem. To make them lighter, you can use:
```cpp
ios::sync_with_stdio(0);
cin.tie(0);
```
This helps to make the code more efficient by decoupling it from the C language.

## Efficiency Tip

The newline character "\n" works faster than endl because endl causes a flush operation (clears the program's buffer memory).

You can read entire lines as a string using:
```cpp
getline(cin, s);
```
And you can use files for input and output with:
```cpp
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
```
