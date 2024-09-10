# Shape Drawer

## Description
A GUI application using C++ and the Qt framework.

## Prerequisites
- Qt framework installed (Qt 5.x , 5.15 or higher)
- C++ compiler

```markdown
## Build Instructions
1. Clone the repository:
git clone https://github.com/Hovo00/QShapeDrawer.git
cd QShapeDrawer
2. Build the project using qmake:
mkdir build_dir && cd build_dir
qmake .. && make
```
```
## Run Instructions
1. Execute the compiled program:
./shape_drawer.app/Contents/Linux/shape_drawer ## Path can differ on your system
## Usage
1. Issues

    For the command to work correctly, there should be no spaces inside the tokens (additional spaces between tokens or at the end of command are okay). You will see syntax error logs for any of the following cases and the program will continue execution.
    1. `create_line -name {line_1} -coord_1 {50, 50} -coord_2 {300, 500}` // because `{300` and `500}` will be treated as separate tokens.
    2. `create_triangle -name {triangle 1} -coord_1 {0,0} -coord_2 {10,0} -coord_3 {50,60}`

    3. There are no naming rules (characters, etc.) inside the `{}` brackets for names, only they must not be empty.

2. Limitations
    1. Shape names can't have duplications
        `create_square -name {shape_1} -coord_1 {50,50} -coord_2 {300,500}`
        `create_line -name {shape_1} -coord_1 {50,50} -coord_2 {400,600}` // In this case, the program will log a message that a shape with that name is already defined.
    2. `connect -object_name_1 {rect_1} -object_name_2 {line_1}` // If you try to connect non-existing objects, a log about the error will be displayed.
    3. Object names can't be empty strings.
    4. Coordinates can contain digits, `.`, and `{,}` and only one of each. `{200,32c}`, `{{kdsa}}` are syntax errors
    5. Coordinates should be inside the Canvas dimension, otherwise an "out of canvas" error will occur.
    6. Incomplete commands will not be executed.
    7. Coordinates can't contain `-` sign
    In all these cases, execution will continue.

3. Additional features
    1. For all wrong inputs, the token which leads to the problem will be highlighted in logWindow.