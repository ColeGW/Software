# Lab assignment: Cloning libraries and example code

The bulk of Lab 1 is covered in a handout. To complete the handout, however, you will need some libraries and sample codes. In general, our plan is to provide skeleton codes and demos and each week you'll add new functionality to your Romi through libraries that either we provide or you create.

**Because you will be editing libraries that we provide, you will need to make local copies on your machine** and point to them using `lib_extra_dirs` in platformio.

For this lab, you will be introduced to Git and Github and _clone_ some libraries. In the future, you will submit your work through Github Classroom, but for now, let's just get some code.  

## Step 0: Get set up with Git and Github

Explained on Canvas.

## Step 1: Clone this repository to your computer

Clone this repository to your local machine. At the command line, you can type

```
git clone <PASTE THE REPO ADDRESS HERE>
```

Alternatively, you can clone it from within VSCode.

The repository contains both library files and example codes, one for each of the MaxBotix interfaces.

## Step 2: Open a project folder in VSCode

Open one of the project folders. Each student should do one of the examples. To avoid merge conflicts (we'll discuss those another day), you should do each of the three interfaces serially: Student A clones, edits, and pushes. Then Student B does the same. It's not _quite_ the spirit of Git, but if you're just getting started with Git, it's safer.

## Step 3: Point platformio to your local directories
You are used to using `lip_deps` for including libraries in platformio. `lib_deps` works well for stable libraries. When you use `lib_deps`, platformio makes a _temporary_ copy of the library on your computer. You can edit it, if you wish, but your changes will be clobbered if you ever download the library again.

Instead, you'll want to use `lib_extra_dirs`, which points platformio to a _local_ directory on your computer. Since your code was obtained using Git, you will now have full version control for any changes you make to the libraries (which will happen frequently).

Because everyones' computer is set up differently, we **have not included `platformio.ini` files** in the repo. If we did, then you'd have re-enter the `lib_extra_dirs` parameters each time you shared code. Instead, you'll need to make `platformio.ini` files from this template:

```
[env:a-star32U4]
platform = atmelavr
board = a-star32U4
framework = arduino

lib_extra_dirs =
    /Users/greg/Documents/PlatformIO/rbe/rbe-2002-class-repos/rbe2002-week01/lib/Rangefinder
    /Users/greg/Documents/PlatformIO/rbe/rbe-2002-class-repos/rbe2002-week01/lib/Romi-32u4-utilities
    
monitor_speed = 115200
```

Obviously, you'll need to change the actual directories. Note that we have included `platformio.ini` in the `.gitignore` file.

## Step 4: Upload a program to your Romi

Return to the Lab Worksheet, upload the code, and answer the questions.
