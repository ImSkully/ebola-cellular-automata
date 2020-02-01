# Cellular Automata Simulating Ebola
The simulation of the spread of the Ebola virus in a Cellular Automata made using C. Working program has functionality in both a serial and parallel computing environment, along with a visualization web application built with PHP.

## Usage
1. Adjust output parameters in the header.h of the respective program. *(Parallel/Serial)*
2. Execute the program and allow sufficient time for generation, `./ebola` or use the makefile `make quickrun`.
3. Once execution has completed, copy the contents of the `/output` directory and copy it to `ebola-visualization/public`.
	* `api.php` - Contains definitions taken from the header.h during execution which defines the world parameters.
	* `data.json` - Raw JSON data which contains the results of generation, this gets larger depending on the number of generations that were executed, a safe bet is to usually generate around 1-500.

## makefile
The following pre-existing commands are defined in the makefiles in both versions of the program:
 * `quickrun`
 Generates, compiles and then executes the program.
 * `generate`
 Generates the output binary files for the C program.
 * `compile`
 Compiles the C binary files, requires generated output files to work.
 * `clean`
 Cleans up the working directory of all output files and the executable, this should only be done when rebuilding.
