'''
Python 6 nodarbības mājasdarbs Nr.2

Uzdevums: aizpildīt vietas ar atzīmi TODO
'''
import matplotlib.pyplot as plt
import json
import numpy as np

# Importēt failu "top_vardi.json" un saglabāt atslēgas kā listi ar nosaukumu "x"
# vērtības kā listi ar nosaukumu "y"
# TODO  
f = open('top_vardi.json')
data = json.load(f)
x = data.keys()
y = data.values()

# izveidot stabiņveidu grafiku kas rāda vārdu biežumu (y ass), Vārdus uz x ass
# piemērs ir mājasdarbu failā
fig, ax = plt.subplots()
# TODO
ax.bar(x, y)
plt.show()



