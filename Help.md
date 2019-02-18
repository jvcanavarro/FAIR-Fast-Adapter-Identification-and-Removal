FAIR - Fast Adapter Identification and Removal v1.0

Usage: /home/fmiranda/bin/FAIR/fair -o <output_dir> [options]

Basic options:
-o/--output   <output_dir>   directory to store all the resulting files (required)
-h/--help                    prints this usage message
-v/--version                 prints version

Input data:
-s/--single        <filename>    file with unpaired reads
-f/--forward       <filename>    file with forward paired-end reads
-r/--reverse       <filename>    file with reverse paired-end reads
-i/--interlaced    <filename>    file with interlaced forward and reverse paired-end reads

Pipeline options:
--only-identify         runs only adapter identification (without removal)
--only-remove           runs only adapter removal (without identification)
                        need to set adapter(s) if this option is set
--trim                  trim ambiguous bases (N) at 5'/3' termini
--trim-quality          trim bases at 5'/3' termini with quality scores <= to
                        --min-quality value
--min-quality   <int>   minimal quality value to trim

Advanced options:
--adapter     <adapter>         adapter sequence that will be removed (unpaired reads)
                                required with --only-remove
--forward-adapter   <adapter>   adapter sequence that will be removed
                                in the forward paired-end reads (required with --only-remove)
--reverse-adapter   <adapter>   adapter sequence that will be removed
                                in the reverse paired-end reads (required with --only-remove)
-t/--threads    <int>           number of threads
                                [default: 1]
--phred-offset    <33 or 64>    PHRED quality offset in the input reads (33 or 64)
                                [default: auto-detect]