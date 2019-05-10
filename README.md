# Mazer

**COSC2131 - Programming Using C++**

Assignment 2 of RMIT Programming Using C++ Course: **_Mazer_**

Lecturer: _Andrew Smith_

Student: _Le Nguyen Anh Tuan (s3574983)_


**How to use (type these commands):**

1.  Changer current directory to project folder directory

    `cd folder-of-the-project`

2.  Compile project

    `cmake .`

3.  Build project

    `make`

4.  Run project (execution file)

    `./s3574983_a2`

**Accomplished functions:**

1.  Generating maze with three algorithms (Hunt and Kill, Growing Tree, Prim's, Recursive Backtracking) with seed

    `--gh` or `--gg` or `--gp` or `--gr` + `seed width height` + save svg or/and save binary (`--sv` or `--sb`)

2.  Generating maze with three algorithms (Hunt and Kill, Growing Tree, Prim's, Recursive Backtracking) with/without seed

    `-gh` or `-gg` or `-gp` or `-gr` + `seed width height` or `width heigh` + save svg or/and save binary (`--sv` or `--sb`)

3.  Save binary

    Generating maze with/without seed (`--gh` or `--gg` or `--gp` or `--gr`) + `--sb filename.maze`

4.  Save svg

    Generating maze with/without seed (`-gh` or `-gg` or `-gp` or `-gr`) + `--sv filename.svg`

5.  Additional functions

- Validate user input (partially)

    - **_WARNING:_** **There might be `Segmentation fault: 11` due to some problems with my user's input processor, please re-run execution file and try again.**

- Timing when generating and saving

    - **If you want to switch into benchmarking mode, please comment out `getUserInput();`, uncomment `benchmark();` in main function of `main.cpp` and compile + build + run the project again. _It will take more than three hours to complete._**

    - Benchmark results
    
        - Benchmark [setup](https://github.com/95tuanle/Mazer-2/blob/master/Setup.png)
        
            - Processor 2-core 4-thread Intel Core i5-5257U@2.7 GHz
            
            - Memory 16 GB 1867 MHz DDR3
            
            - Graphics Intel Iris Graphic 6100 1536 MB
            
            - OS macOS Mojave version 10.14.4
        
        - Benchmark cases
        
            - 10 times of generating Growing Tree maze (2000 x 2000) + saving SVG + saving binary
            
            - 10 times of generating Prim's maze (2000 x 2000) + saving SVG + saving binary
            
            - 10 times of generating Recursive Backtracking maze (2000 x 2000) + saving SVG + saving binary
            
        - [Results](https://github.com/95tuanle/Mazer-2/blob/master/Result.png)
        
        
        Average Growing Tree runtime is 611010 milliseconds

        Average Prim's runtime is 584978 milliseconds

        Average Recursive Backtracking runtime is 40084 milliseconds
        
        
~~Unaccomplished functions:~~

~~1. Load binary~~

~~2. Load svg~~

~~3. Maze-routing algorithm~~

