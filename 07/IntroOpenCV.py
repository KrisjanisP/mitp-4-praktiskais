#!/usr/bin/env python3
'''
Python 7 nodarbības mājasdarbs Nr.2

Uzdevums: aizpildīt vietas ar atzīmi TODO

Izveidot klasi, kura pārveido 5. nodarbības mājasdarbu Nr. 3 saturu par klasi
'''

class IntroOpenCV:
    '''
    Izveidot klasi, kurai ir 5 publiskas metodes:
    - setBilde -  definē bildes failu
    - bilde 
    - melnbalts
    - EdgeDetection
    - ZilsSarkans

    !Klasei nav neviena publiski pieejami parametri!
    '''
    def set_picture(self,BildeFails):
        self.__picture = BildeFails

    def get_picture(self):
        # izsaucot šo metodi izvada Originālbildi . Originālbilde self.__bilde
        # TODO
        return 0

    def get_black_white(self):
        # izsaucot šo metodi izvada melnbaltu bildi. Originālbilde self.__bilde
        # TODO
        return 0

    def get_edge_detection(self):
        # izsaucot šo metodi izvada bildi ar Caddy edge detection. Originālbilde self.__bilde
        # TODO
        return 0

    def get_blue_red(self):
        # izsaucot šo metodi izvada bildi, kura apmaina zilo krāsu ar sarkanu. Originālbilde self.__bilde
        # TODO
        return 0


if __name__ == "__main__":
    obj = IntroOpenCV()
    obj.set_picture("python.jpg")
