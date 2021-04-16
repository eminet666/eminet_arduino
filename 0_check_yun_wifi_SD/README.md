# INITIALISATION/VERIFICATION

## programmes disponibles
* YunDiskSpeceExpander  : configuration de la carte SD (partition, formatage)
* YunFirstConfig        : configuration pour accès de la carte Yun au réseau local
* WifiStatus            : vérification de la connexion au réseau local en wifi
* test_SD_write         : test d'écriture sur carte SD
* test_SD_URL_access    : test d'accès à la carte SD par URL à partir d'un navigateur


## scénarios

### CONFIGURATION (la première fois ou réinit en cas de problème)
* réinitialiser la carte appuyer 5" sur reset wifi et arduino
* vérifier présence réseau Arduino-Yun dans les réseaux disponibles
* se connecter au réseau Arduino-Yun
* accéder au menu de config à l'adresse 192.168.240.1
* configurer le wifi dans le menu

## RE-CONFIGURATION (changement de réseau local)
* lancer YunFirstConfig pour configurer 

## VERIFICATIONS (déjà configuré)
* accès au wifi     : WifiStatus
* écriture sur SD   : test_SD_write
* accès SD par URL  : test_SD_URL_access

## ACCES TERMINAL EN SSH (connexion sécurisée)
* avec logiciel putty sur windows (à télécharger)
* interface : ipadress puis open
* authentification : id=root, password=wifipassword (exp : Arduino7)
* commandes : commandes linux comme : ls /mnt/sda1

remarque : http://ipadress/sd pointe sur /mnt/sda1/arduino/www



