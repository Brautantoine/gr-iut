# La mécanique #

Cette partie concerne tous les aspects mécaniques de la grue.

<img src="https://github.com/Brautantoine/gr-iut/blob/master/CAO/MECA/Ressource/Screen/preview_angle.png" alt="drawing" width="460"/>
<img src="https://github.com/Brautantoine/gr-iut/blob/master/CAO/MECA/Ressource/Synoptique/preview_front.png" alt="drawing" width="460"/>
<img src="https://github.com/Brautantoine/gr-iut/blob/master/CAO/MECA/Ressource/Synoptique/preview_top.png" alt="drawing" width="460"/>

## Les différents mouvements de la grue ##

La grue s'articule autour de trois mouvements.

* Un mouvement linéaire pour déplacer la pince

* Un mouvement d'enroulement pour monter et descendre la pince

* Un mouvement de pivot grâce à courroie pour faire tourner le haut de la grue

Pour déplacer linéairement la pince, celle-ci est reliée à un chariot sur un rail de guidage linéaire. Le chariot choisi est un chariot IGUS en polymère. Il est entraîné grâce à une courroie montée sur un moteur à courant continu. Le mouvement du chariot est limité grâce à deux buttées de fin de course (bouton poussoir).

Afin de lever et descendre la pince, son câble est relié à un enrouleur entraîné par un moteur à courant continu. Le moteur permet d'ajuster la hauteur de la pince et est automatiquement actionné lorsque le chariot se déplace afin de toujours avoir la longueur de câble nécessaire.

Pour faire pivoter la grue sur son axe, une courroie relie un point fixe sur la base de la grue et une poulie reliée à un moteur pas à pas sur la partie mobile. En tournant, le moteur pas à pas fait tourner la poulie le long de la courroie, entraînant ainsi la partie mobile de la grue.

## La structure de la grue ##

1. Le socle

La base de la grue consiste en un cube en bois de 30x30x6 cm. Il est constitué de planches de 8mm découpées au laser et assemblées grâce à la technique du Tenon Mortaise. Le socle possède une ouverture à l'avant afin d'y passer les câbles ainsi que des encoches pour accueillir la tour de la grue. Si jamais le socle se révèle trop léger, il est possible de le lester en insérant des poids à travers la fente.

2. La tour

La tour est constituée d'un rectangle de 8x8x60 cm ainsi que de 4 triangles de 15x12x8 cm. Le rectangle de la tour s'insère dans le socle et les triangles font la jonction entre les deux sur les 4 faces de la tour. Au sommet de la tour, le rectangle est fermé par une pièce de renfort qui accueillera la jonction vers la partie mobile.

3. La jonction

La jonction est constituée de 2 pièces imprimées en 3D. L'une est reliée à la partie fixe de la grue et accueille le roulement à billes qui assure le pivot de la grue. C'est aussi autour de cette pièce que se fixe la courroie assurant le pivot. L'autre est reliée à la partie mobile et est constituée d'une petite plaque sur laquelle est reliée un cylindre. Ce cylindre passe à travers le roulement à billes pour permettre la jonction entre les deux parties. Pour assurer un contact optimal au niveau du roulement à billes, un chanfrein est présent entre le cylindre et la plaque.

4. La partie mobile

La partie mobile est constituée d'une planche de 75x10x0.6 cm. On y retrouve toutes les fixations nécesaires afin d'y installer les moteurs et le rail.

>Pour faire parvenir les câbles de la base jusqu'au haut de la grue, toutes les pièces centrales sont percées d'un trou de 5cm de diamètre.
