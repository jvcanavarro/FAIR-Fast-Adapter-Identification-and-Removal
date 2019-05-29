# FAIR-Fast-Adapter-Identification-and-Removal

TODO:
- Identificação de Adaptador.
- Makefile / install.sh
- Trim Sequence / Min Quality / Trim Quality: essa parte é possível implementar em poucas horas, já que na classe SingleFASTQ já temos implementada uma função de análise de qualidade (33 ou 64).
- Implementação de Threads.
- Suporte para Interlaced Sequences.

Usage:
./FAIR --output tests/ --single amostra1.fastq --only-remove --adapter CCCCC

./FAIR --output tests/ --reverse amostra1.fastq --forward amostra2.fastq --only-remove --forward-adapter CCCCC --reverse-adapter CCCCC
