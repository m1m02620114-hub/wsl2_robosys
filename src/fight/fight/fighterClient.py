class player:
    def __init__(self, Pname, Pnum, m1, m2, m3):
        self.Pname = Pname
        self.m1 = m1
        self.m2 = m2
        self.m3 = m3

    def defeat(self):
        return m1.hp and m2.hp and m3.hp <= 0


class Monster:
    def __init__(self, Mname, hp, speed, attack, defence, Pname):
        self.Mname = Mname
        self.hp = hp
        self.speed = speed
        self.attack = attack
        self.defence = defence
        self.Pname = Pname

        def dead(self):
            return self.hp <= 0

            
            

class Situation:
    def __init__(self, hp1, s1, a1, d1, hp2, s2, a2, d2):
        self.hp1 = hp1
        self.s1 = s1
        self.a1 = a1
        self.d1 = d1
        self.hp2 = hp2
        self.s2 = s2
        self.a2 = a2
        self.d2 = d2
        self.a1_p = 0
        self.d1_p = 0
        self.a2_p = 0
        self.d2_p = 0

        def speed(self):
            return s1 <= s2

        def offdef(self):
            if speed():
                hp2_f = self.hp2 + self.d2 - self.a1
                if hp2_f < self.hp2:
                    self.hp2 = hp2_f
                self.d2 = 0
                self.a1 = 0
            else:
                hp1_f = self.hp1 + self.d1 - self.a2
                if hp1_f < self.hp1:
                    self.hp1 = hp1_f
                self.d1 = 0
                self.a2 = 0


class A(Monster):
    def __init__(self, Mname = "A", hp = 50, speed = 5, attack = 10, defence = 10, Pname = player):
        super().__init__(Mname, hp, speed, attack, defence)