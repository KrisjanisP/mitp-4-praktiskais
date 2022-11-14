'''
Python 7 nodarbības mājasdarbs Nr.2

Uzdevums: aizpildīt vietas ar atzīmi TODO

Izveidot klasi, kura pārveido 5. nodarbības mājasdarbu Nr. 3 saturu par klasi
'''
import cv2

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
        self.__bilde = cv2.imread(BildeFails)

    def get_picture(self):
        # izsaucot šo metodi izvada Originālbildi . Originālbilde self.__bilde
        # TODO
        cv2.imshow('image', self.__bilde)
        cv2.waitKey(0)
        return 0

    def get_black_white(self):
        # izsaucot šo metodi izvada melnbaltu bildi. Originālbilde self.__bilde
        # TODO
        img_melnbalts = cv2.cvtColor(self.__bilde, cv2.COLOR_BGR2GRAY) # TODO
        cv2.imshow('image', img_melnbalts)
        cv2.waitKey(0)
        return 0

    def get_edge_detection(self):
        # izsaucot šo metodi izvada bildi ar Caddy edge detection. Originālbilde self.__bilde
        # TODO
        img_caddy = cv2.Canny(image = self.__bilde, threshold1=100, threshold2=200) # TODO
        cv2.imshow('image', img_caddy)
        cv2.waitKey(0)
        return 0

    def get_blue_red(self):
        # izsaucot šo metodi izvada bildi, kura apmaina zilo krāsu ar sarkanu. Originālbilde self.__bilde
        # TODO
        img_zils_sarkans = cv2.cvtColor(self.__bilde, cv2.COLOR_BGR2RGB) # TODO
        cv2.imshow('image', img_zils_sarkans)
        cv2.waitKey(0)
        return 0


if __name__ == "__main__":
    obj = IntroOpenCV()
    obj.set_picture("python.jpg")
    obj.get_picture()
    obj.get_black_white()
    obj.get_edge_detection()
    obj.get_blue_red()
