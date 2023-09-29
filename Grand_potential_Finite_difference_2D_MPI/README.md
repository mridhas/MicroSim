This is multiphase multi-component phase-field solver based on the
grand-potential formalism. The solver is parallelized using MPI on
CPUs and requires the h5pcc compiler for compilation and execution.

Compilation can be done by a simple "make".

For running the code on the cluster please use a script.
For testing on your desktops/laptops the following execution command is required:

`mpirun -np num_processors ./microsim_gp name_of_infile name_of_filling_file name_of_output_files`

For .h5 files, with WRITEHDF5=1, output files need to be transformed in .xml format using the following command
just above the DATA folder that is created upon execution.

`./write_xdmf name_of_infile name_of_output_file total_no_workers start_time end_time`

For ASCII files in .vtk format the consolidated output files needs to be reconstructed out of separate processor files
that are written in the DATA folder that is created upon execution

`./reconstruct name_of_infile name_of_output_file number_of_workers start_time end_time`


The code has been developed at IISc Bangalore, Department of Materials
Engineering by Prof. Abhik Choudhury.

The code is built on work by past PhD students

a) Sumeet Rajesh Khanna
