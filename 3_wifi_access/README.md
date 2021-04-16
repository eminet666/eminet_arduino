# UTILISATION DEPUIS NAVIGATEUR (accès en wifi)

## programmes disponibles
* test_rest_api      : pilotage de la Yun par commandes via URL
* test_CORS_enabled  : idem avec CORS enabled construction
* test_html_ctrl     : pilotage de la Yun par fichier HTML via URL
* test_sensor_values : lecture en boucle de A1 par fichier HTML via URL


## URL access
### 2 syntaxes possibles :
* http://arduinoname.local/          (exp : http://arduino7.local)
* http://ipadress/ puis prompt       (exp : http://192.168.0.133)
* http://root:wifipassword@ipadress/ (exp : http://root:Arduino7@192.168.0.133)

### contrôle d'accès (choisir à la configuration, accès à la REST api en "open" ou "with password")
* prompt  : id=root & psw=wifipassword
* exemple : id=root & psw=Arduino7

### type d'accès
* REST api : http://ipadress/arduino/commande (exp : http://ipadress/arduino/digital/13/0)
* HTML     : http://ipadress/sd/rep/file.ext  (exp : http://ipadress/sd/test_sensor_values)

## remarques :   
* [client.println(F(“”))](https://forum.arduino.cc/t/client-println-f/154089) : place le contenu directement en mémoire flash
* fonction YunServer / YunClient depreciated


