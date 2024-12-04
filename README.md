# CLI Artwork with ncurses

This project is a simple CLI program that generates a random "starfield" on the terminal, created using the ncurses library. The stars appear at random positions and are refreshed at a fixed interval, creating a twinkling effect.
Features

    - Random star placement: Stars are randomly placed on the terminal screen.
    - Dynamic twinkling effect: The screen refreshes to give a twinkling appearance.
    - Configurable star density: Adjust the density of stars by modifying the code.
     -Graceful exit: Exit the program anytime by pressing the q key.

=====

## Requirements

Before compiling the program, ensure the following dependencies are installed:

    C Compiler: GCC or Clang.
    ncurses Library: A terminal control library for Unix-like systems.

On a Debian-based system, you can install ncurses with:

    sudo apt update
    sudo apt install libncurses5-dev libncursesw5-dev

Compiling the Program

To compile the program, use the following command:

    gcc -o starfield star.c -lncurses


If you're using another compiler (e.g., Clang), ensure you include the -lncurses flag as well.