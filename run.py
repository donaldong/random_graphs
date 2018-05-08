import subprocess
import csv

with open('connected-n9m18.csv', 'w') as csvfile:
    fieldnames = ['chromatic_number', 'chromatic_index', 'hamiltonian_path', 'hamiltonian_cycle']
    writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
    writer.writeheader()
    for i in range(100000):
        p = subprocess.Popen(['python3', 'gnm.py'], 
            stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        out, err = p.communicate(input=b'9 18')
        p = subprocess.Popen(['./chromatic_number.o'], 
            stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        x, err = p.communicate(input=out)
        x = int(x)
        p = subprocess.Popen(['./chromatic_index.o'], 
            stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        x_, err = p.communicate(input=out)
        x_ = int(x_)
        p = subprocess.Popen(['./hamiltonian.o'], 
            stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        hout, err = p.communicate(input=out)
        hout = str(hout)
        c = 'c' in hout
        p = 'p' in hout
        writer.writerow({
            'chromatic_number': x,
            'chromatic_index': x_,
            'hamiltonian_path': p,
            'hamiltonian_cycle': c
        })

