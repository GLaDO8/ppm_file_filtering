# ppm_file_filtering

## Synopsis

This is a CLI-based ppm filtering tool is written in C++ and works on .ppm files.
.ppm files are portable pixmap format. It was created in the 80s for usage in E-mails. 
The format of a .ppm file looks like this. 
```
P3
3 2
255
#The part above is the header
#"P3" means this is a RGB colour image in ASCII
#"3 2" is the width and height of the image in pixels
#"255" is the maximum value for each colour
#The part below is image data: RGB triplets
255   0   0     0 255   0     0   0 255
255 255   0   255 255 255     0   0   0
```
**NOTE**
.ppm files are huge files because of the absence of image compression mechanisms and other file-reduction techniques. 

## Usage
In order to use this tool: 
* Download and unzip the repo into a folder 
* Open a terminal inside the folder 
* Run the following command
```
$ g++ *.cpp
```
* Follow the instructions in the terminal.



