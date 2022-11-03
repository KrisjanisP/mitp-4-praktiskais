#!/usr/bin/env python3
'''
Python 6 nodarbības mājasdarbs Nr.1

Uzdevums: aizpildīt vietas ar atzīmi TODO
'''
import numpy as np

# izveidot numpy random 3x3 matricu
arr = [] # TODO np.random.rand(3,3)

# izveidot citu numpy matricu, kas ir inversā matrica no pirmās matricas
arr_inv = arr # TODO np.linalg.inv(arr) 

# sareizināt abas matricas un noapaļot līdz integer precizitātei
reizinājums = [] # TODO

# Izveidot trešo matricu, kas ir 3x3 identitātes matrica 
identitates_matrica = [] # TODO

# Pārbaudīt vai identitates_matrica ir vienāda ar reizinājumu!
vienads = bool()

# Lai pārbaudītu iznākumu, atkomentēt nākamo rindu
# assert vienads == True