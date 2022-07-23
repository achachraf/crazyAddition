# Crazy Addition
### /!\ _Disclaimer: I made this project just as a pastetime and not having a real purpose, I just enjoy implement crazy ideas. For serious project, check other repos, thanks :)._


## Introduction
There is no introduction, this is a useless code to make the simple addition operation with the most sophisticated way, it's not optimized, doesn't implement any theoretical architecure nor conception, but only sophisticate the addition operation by generating a __python__ script contains all results of possible combinaison hardcoded in a dictionnary, so we doesn't operate the literally the addition operation.

## Mechanism
1. A C++ take in input number of operands in your addition and the range of you operands
2. The C++ program generate all combinations and associate each with a result
3. Generate python script as an ouput 
4. The python script that takes your operands values as input
5. The script construct a key based on your operands and sort it (this is to not repeate combinaison as the addition is commutative)
6. search the key in the dictionnary and retreive the value
7. output the value


## Usage

Run compile & run the C++ file _main.cpp_ as following
```shell
$ g++ -o main main.cpp
$ ./main <number_of_operands> <left_side_range> <right_side_range>
```
Run the python generated script file to make your greate complicated addition

```shell
$ python ./crazyAdditionScript.py
```
Then you will asked to enter your operands as input stream

>Alert: Don't open the crazyAdditionScript.py it could be too large, so make your editor freeze.