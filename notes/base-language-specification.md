# Language Specification

A variable's name must be a string of non-whitespace characters which starts with a letter.
All variables have unsinged integer types.

A variable can only be assigned to one of the following:
1. A literal value
2. A variable 
3. A binary operation 
4. A function call 

Here are examples:
```
x = 7
x = y
x = x + 1
x = a * b
x = my_func(a, b, c)
```

If the specified variable doesn't already exist in the current scope, it will be initialized when assigned.

Valid binary operators are: 
```
+, -, *, /, %, >, <, >=, <=, ==, !=, &&, ||
```

If statements are written as such:
```
if ([condition]) {

}
else {

}
```
`[condition]` must be a binary operation.

While loops are similar:
```
while ([condition]) {

}
```

Functions are defined as such:
```
function (a, b) {
    a = a + 1
    return a * b
}
```
A function can have any number of parameters.
A function does not have to have a return statement, but if it does, 
the return value must be a literal, variable, binary operation, or function call.
Functions are not able to access any variables outside their scope.
Functions cannot be recursive.
The arguments for a function call must be variables or literal values.

Finally, you can use `print()` to print things.
The argument must be a literal, variable, binary operation, or function call.
