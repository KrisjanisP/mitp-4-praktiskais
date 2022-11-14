#!/usr/bin/env python3
'''
Python 7 mājasdarbs Nr.2

Uzdevums: aizpildīt vietas ar atzīmi TODO

Izveidot klasi, kura pārveido 5. nodarbības mājasdarbu Nr. 2 saturu par klasi

'''

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
        return 0


if __name__ == "__main__":
    obj = TopWords()
    obj.set_dict("top_vardi.json")
