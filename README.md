# Minishell

Minishell is a simple shell program created as part of the 42 Common Core curriculum. It aims to replicate basic functionalities of the Unix shell while adhering to specific project requirements. Minishell can handle various shell commands, environment variables, redirections, pipes, and more.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Configuration](#configuration)
- [Examples](#examples)
- [Troubleshooting](#troubleshooting)
- [Contributors](#contributors)
- [License](#license)

## Introduction

Minishell is designed to emulate a Unix shell with a subset of its functionalities. The project includes handling commands, managing processes, and interpreting various shell-specific syntax and built-in functions. The bonus part of the project also includes logical operators and wildcard handling.

## Features

- Display a prompt when waiting for a new command.
- Command history support.
- Search and execute commands based on the `PATH` variable or using a relative/absolute path.
- Signal handling with a single global variable.
- Quote handling:
  - Single quotes (`'`) prevent interpretation of metacharacters.
  - Double quotes (`"`) prevent interpretation except for `$`.
- Input and output redirections:
  - `<` for input redirection.
  - `>` for output redirection.
  - `<<` for here-documents.
  - `>>` for appending output redirection.
- Pipe implementation (`|`).
- Environment variable expansion (`$`).
- Special variable handling (`$?` for exit status).
- Control characters:
  - `ctrl-C` displays a new prompt.
  - `ctrl-D` exits the shell.
  - `ctrl-\` does nothing.
- Built-in commands:
  - `echo` with `-n` option.
  - `cd` with relative or absolute path.
  - `pwd` with no options.
  - `export` with no options.
  - `unset` with no options.
  - `env` with no options or arguments.
  - `exit` with no options.

### Bonus Features

- Logical operators `&&` and `||` with parenthesis for priority.
- Wildcard (`*`) handling for the current working directory.

## Installation

To install Minishell, follow these steps:

1. Clone the repository:
    ```sh
    git clone https://github.com/Moyaxzan/42-Minishell
    ```

2. Navigate to the project directory:
    ```sh
    cd minishell
    ```

3. Compile the project:
    ```sh
    make
    ```

## Usage

To start Minishell, run the following command in the project directory:
```sh
./minishell
