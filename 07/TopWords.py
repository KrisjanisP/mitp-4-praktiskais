'''
Python 7 mājasdarbs Nr.2

Uzdevums: aizpildīt vietas ar atzīmi TODO

Izveidot klasi, kura pārveido 5. nodarbības mājasdarbu Nr. 2 saturu par klasi

'''

import matplotlib.pyplot as plt
import json

class TopWords:
    '''
    Izveidot klasi, kurai ir 2 publiskas metodes:
    - setVardnica -  definē failu
    - grafiks - izvada grafiku

    Klasei nav pieejami publiski parametri
    '''
    def set_dict(self,vardnicaFails):
        self.__vardnica = vardnicaFails

    def get_bar_plot(self):
        # izsaucot šo metodi izvada bar tipa grafiku. dati ir parametrs __vardnica
        # TODO        
        f = open('top_vardi.json')
        data = json.load(f)
        x = data.keys()
        y = data.values()
        plt.figure(figsize=(13, 5))
        plt.title('Top vārdi')
        plt.bar(x, y)
        plt.show()
        return 0


if __name__ == "__main__":
    obj = TopWords()
    obj.set_dict("top_vardi.json")
    obj.get_bar_plot()
