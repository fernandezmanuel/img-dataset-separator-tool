# Image Dataset Separator Tool

## Getting Started

A C++ mini tool to randomly separate jpg images into two different dataset folders for machine learning purposes. (/test and /training)

---

### Instructions

1. Clone this repository.
    ```sh
    git clone https://github.com/fernandezmanuel/img-dataset-separator-tool .git
    cd img-dataset-separator-tool 
    ```
    
2. Add all you sample images into any directory and rename each of them to 'sample{xx}.jpg'
    ```sh
    Eg:
       sample01.jpg
       sample02.jpg
       sample03.jpg
       ...
    ```
    
3. Compile and run using makefiles.
    ```sh
    make clean all
    ./mainprog
    ```
 ---
 
 ### License

[GNU](LICENSE.md) - Public Domain
