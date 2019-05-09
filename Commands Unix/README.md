# Comandos para GNU/Linux
---
---

# Archivos y Directorios

---
Entrar en el directorio **home**.
```bash
~$  cd /home
```

---
Retroceder un nivel.
```bash
~$  cd ..
```

---
Retroceder 2 niveles.
```bash
~$  cd ../../
```

---
Ir al directorio ra�z.
```bash
~$  cd
```

---
Ir al directorio user1.
```bash
~$  cd ~user1
```

---
Regresar al directorio anterior. Equivalente a hacer `cd .. && pwd`.
```bash
~$  cd �
```

---
Mostrar la ruta del directorio actual.
```bash
~$  pwd
```

---
Ver los ficheros de un directorio.
```bash
~$  ls
```

---
Ver los ficheros de un directorio.
```bash
~$  ls -F
```

---
Mostrar los permisos de los ficheros y carpetas de un directorio.
```bash
~$  ls -l
```

---
Mostrar los ficheros ocultos.
```bash
~$  ls -a
```

---
Mostrar los ficheros y carpetas que contienen n�meros.
```bash
~$  ls *[0-9]*
```

---
Mostrar los ficheros y carpetas en forma de �rbol comenzando por la ra�z.(1)
```bash
~$  tree
```

---
Mostrar los ficheros y carpetas en forma de �rbol comenzando por la ra�z.(2)
```bash
~$  lstree
```

---
Crear una carpeta o directorio con nombre **dir1**.
```bash
~$  mkdir dir1
```

---
Crear dos carpetas o directorios simult�neamente (crear dos directorios a la vez).
```bash
~$  mkdir dir1 dir2
```

---
Crear un �rbol de directorios.
```bash
~$  mkdir -p /tmp/dir1/dir2
```

---
Borrar el fichero llamado **file1**.
```bash
~$  rm -f file1
```

---
Borrar la carpeta llamada **dir1**.
```bash
~$  rmdir dir1
```

---
Eliminar una carpeta llamada **dir1** con su contenido de forma recursiva. (si lo borro recursivo estoy diciendo que es con su contenido).
```bash
~$  rm -rf dir1
```

---
Borrar dos carpetas (directorios) con su contenido de forma recursiva.
```bash
~$  rm -rf dir1 dir2
```

---
Renombrar o mover un fichero o carpeta (directorio).
```bash
~$  mv dir1 new_dir
```

---
Copiar un fichero.
```bash
~$  cp file1
```

---
Copiar dos ficheros al un�sono.
```bash
~$  cp file1 file2
```

---
Copiar todos los ficheros de un directorio dentro del directorio de trabajo actual.
```bash
~$  cp dir /* .
```

---
Copiar un directorio dentro del directorio actual de trabajo.
```bash
~$  cp -a /tmp/dir1 .
```

---
Copiar un directorio.
```bash
~$  cp -a dir1
```

---
Copiar dos directorio al un�sono.
```bash
~$  cp -a dir1 dir2
```

---
Crear un enlace simb�lico al fichero o directorio.
```bash
~$  ln -s file1 lnk1
```

---
Crear un enlace f�sico al fichero o directorio.
```bash
~$  ln file1 lnk1
```

---
Modificar el tiempo real (tiempo de creaci�n) de un fichero o directorio.
```bash
~$  touch -t 0712250000 file1
```

---
Salida (volcado en pantalla) del tipo mime de un fichero texto.
```bash
~$  file file1
```

---
Listas de cifrados conocidos.
```bash
~$  iconv -l
```

---
Crea una nueva forma del fichero de entrada asumiendo que est� codificado en from-encoding y convirti�ndolo a to-encoding.
```bash
~$  iconv -f fromEncoding -t toEncoding inputFile > outputFile
```

---
Agrupar ficheros redimensionados en el directorio actual y enviarlos a directorios en vistas de miniaturas (requiere convertir desde imagemagick).
```bash
~$  find . -maxdepth 1 -name *.jpg -print -exec convert '{}' -resize 80�60 'thumbs/{}' 
```

# Encontrar archivos

---
Buscar fichero y directorio a partir de la ra�z del sistema.
```bash
~$  find / -name file1
```

---
Buscar ficheros y directorios pertenecientes al usuario **user1**.
```bash
~$  find / -user user1
```

---
Buscar ficheros con extensi�n **.bin** dentro del directorio **/home/user1**.
```bash
~$  find /home/user1 -name \*.bin
```

---
Buscar ficheros binarios no usados en los �ltimos 100 d�as.
```bash
~$  find /usr/bin -type f -atime +100
```

---
Buscar ficheros creados o cambiados dentro de los �ltimos 10 d�as.
```bash
~$  find /usr/bin -type f -mtime -10
```

---
Buscar ficheros con extensi�n **.rpm** y modificar permisos.
```bash
~$  find / -name \*.rpm -exec chmod 755 �{}� \;
```

---
Buscar ficheros con extensi�n **.rpm** ignorando los dispositivos removibles como cdrom, pen-drive, etc.�
```bash
~$  find / -xdev -name \*.rpm
```

---
Encuentra ficheros con extensi�n **.ps** ejecutados primeramente con el comando **updatedb**.
```bash
~$  locate \*.ps
```

---
Mostrar la ubicaci�n de un fichero binario, de ayuda o fuente.en este caso pregunta d�nde est� el comando **halt**.
```bash
~$  whereis halt
```

---
Mostrar la senda completa (el camino completo) a un binario / ejecutable.
```bash
~$  which halt
```

# Monitoreando y depurando

---
Montar un disco llamado hda2. verifique primero la existencia del directorio **/ mnt/hda2**; si no est�, debe crearlo.
```bash
~$  mount /dev/hda2 /mnt/hda2
```

---
Desmontar un disco llamado hda2. salir primero desde el punto **/mnt/hda2**.
```bash
~$  umount /dev/hda2
```

---
Forzar el desmontaje cuando el dispositivo est� ocupado.
```bash
~$  fuser -km /mnt/hda2
```

---
Correr el desmontaje sin leer el fichero /etc/mtab. �til cuando el fichero es de solo lectura o el disco duro est� lleno.
```bash
~$  umount -n /mnt/hda2
```

---
Montar un disco flexible (floppy).
```bash
~$  mount /dev/fd0 /mnt/floppy
```

---
Montar un cdrom/dvdrom.
```bash
~$  mount /dev/cdrom /mnt/cdrom
```

---
Montar un cd regrabable o un dvdrom.
```bash
~$  mount /dev/hdc /mnt/cdrecorder
```

---
Montar un cd regrabable / dvdrom (un dvd).
```bash
~$  mount /dev/hdb /mnt/cdrecorder
```

---
Montar un fichero o una imagen iso.
```bash
~$  mount -o loop file.iso /mnt/cdrom
```

---
Montar un sistema de ficheros fat32.
```bash
~$  mount -t vfat /dev/hda5 /mnt/hda5
```

---
Montar un usb pen-drive o una memoria (sin especificar el tipode sistema de ficheros).
```bash
~$  mount /dev/sda1 /mnt/usbdisk
```

# Espacio de Disco

---
Mostrar una lista de las particiones montadas.
```bash
~$  df -h
```

---
Mostrar el tama�o de los ficheros y directorios ordenados por tama�o.
```bash
~$  ls -lSr |more
```

---
Estimar el espacio usado por el directorio **dir1**.
```bash
~$  du -sh dir1
```

---
Mostrar el tama�o de los ficheros y directorios ordenados por tama�o.
```bash
~$  du -sk * | sort -rn
```

---
Mostrar el espacio usado por los paquetes rpm instalados organizados por tama�o (fedora, redhat y otros).
```bash
~$  rpm -q -a �qf �%10{SIZE}t%{NAME}n� | sort -k1,1n
```

---
Mostrar el espacio usado por los paquetes instalados, organizados por tama�o (ubuntu, debian y otros).
```bash
~$  dpkg-query -W -f=�${Installed-Size;10}t${Package}n� | sort-k1,1n
```

# Apagar (Reiniciar Sistema o Cerrar Sesi�n)

---
Apagar el sistema (1).
```bash
~$  shutdown -h now
```

---
Apagar el sistema (2).
```bash
~$  init 0
```

---
Apagar el sistema (3).
```bash
~$  telinit 0
```

---
Apagar el sistema (4).
```bash
~$  halt
```

---
Planificar un apagado en hours:minutes
```bash
~$  shutdown -h hours:minutes
```

---
Cancelar un apagado planificado del sistema.
```bash
~$  shutdown -c
```

---
Reiniciar (1).
```bash
~$  shutdown -r now
```

---
Reiniciar (2).
```bash
~$  reboot
```

---
Cerrar sesi�n.
```bash
~$  logout
```

# Permisos en Ficheros (Usa + para colocar permisos y - para eliminar)

---
Mostrar permisos.
```bash
~$  ls -lh
```

---
Dividir la terminal en 5 columnas.
```bash
~$  ls /tmp | pr -T5 -W$COLUMNS
```

---
Colocar permisos de lectura (r), escritura (w) y ejecuci�n(x) al propietario (u), al grupo (g) y a otros (o) sobre el directorio **directory**.
```bash
~$  chmod ugo+rwx directory1
```

---
Quitar permiso de lectura (r), escritura (w) y (x) ejecuci�n al grupo (g) y otros (o) sobre el directorio **directory1**.
```bash
~$  chmod go-rwx directory1
```

---
Cambiar el due�o de un fichero.
```bash
~$  chown user1 file1
```

---
Cambiar el propietario de un directorio y de todos los ficheros y directorios contenidos dentro.
```bash
~$  chown -R user1 directory1
```

---
Cambiar grupo de ficheros.
```bash
~$  chgrp group1 file1
```

---
Cambiar usuario y el grupo propietario de un fichero.
```bash
~$  chown user1:group1 file1
```

---
Visualizar todos los ficheros del sistema con SUID  configurado.
```bash
~$  find / -perm -u+s
```

---
Colocar el bit SUID en un fichero binario. el usuario que corriendo ese fichero adquiere los mismos privilegios como due�o.
```bash
~$  chmod u+s /bin/file1
```

---
Deshabilitar el bit SUID en un fichero binario.
```bash
~$  chmod u-s /bin/file1
```

---
Colocar un bit sgid en un directorio �similar al SUID  pero pordirectorio.
```bash
~$  chmod g+s /home/public
```

---
Desabilitar un bit sgid en un directorio.
```bash
~$  chmod g-s /home/public
```

---
Colocar un bit stiky en un directorio. permite el borrado de ficheros solamente a los due�os leg�timos.
```bash
~$  chmod o+t /home/public
```

---
Desabilitar un bit stiky en un directorio.
```bash
~$  chmod o-t /home/public
```

# Atributos especiales en ficheros (Usa + para colocar permisos y para eliminar)

---
Permite escribir abriendo un fichero solamente modo append.
```bash
~$  chattr +a file1
```

---
Permite que un fichero sea comprimido / descomprimido automaticamente.
```bash
~$  chattr +c file1
```

---
Asegura que el programa ignore borrar los ficheros durante la copia de seguridad.
```bash
~$  chattr +d file1
```

---
Convierte el fichero en invariable, por lo que no puede ser eliminado, alterado, renombrado, ni enlazado.
```bash
~$  chattr +i file1
```

---
Permite que un fichero sea borrado de forma segura.
```bash
~$  chattr +s file1
```

---
Asegura que un fichero sea modificado, los cambios son escritos en modo synchronous como con sync.
```bash
~$  chattr +S file1
```

---
Te permite recuperar el contenido de un fichero a�n si este est� cancelado.
```bash
~$  chattr +u file1
```

---
Mostrar atributos especiales.
```bash
~$  lsattr
```

# Archivos y Ficheros comprimidos

---
Descomprime in fichero llamado **file1.bz2**.
```bash
~$  bunzip2 file1.bz2
```

---
Comprime un fichero llamado **file1**.
```bash
~$  bzip2 file1
```

---
Descomprime un fichero llamado **file1.gz**.
```bash
~$  gunzip file1.gz
```

---
Comprime un fichero llamado **file1**.
```bash
~$  gzip file1
```

---
Comprime con compresi�n m�xima.
```bash
~$  gzip -9 file1
```

---
Crear un fichero rar llamado **file1.rar**.
```bash
~$  rar a file1.rar test_file
```

---
Comprimir **file1**, **file2** y **dir1** simult�neamente.
```bash
~$  rar a file1.rar file1 file2 dir1
```

---
Descomprimir archivo rar.
```bash
~$  rar x file1.rar
```

---
Descomprimir archivo rar.
```bash
~$  unrar x file1.rar
```

---
Crear un tarball descomprimido.
```bash
~$  tar -cvf archive.tar file1
```

---
Crear un archivo conteniendo **file1**, **file** y **dir1**.
```bash
~$  tar -cvf archive.tar file1 file2 dir1
```

---
Mostrar los contenidos de un archivo.
```bash
~$  tar -tf archive.tar
```

---
Extraer un tarball.
```bash
~$  tar -xvf archive.tar
```

---
Extraer un tarball en / tmp.
```bash
~$  tar -xvf archive.tar -C /tmp
```

---
Crear un tarball comprimido dentro de bzip2.
```bash
~$  tar -cvfj archive.tar.bz2 dir1
```

---
Descomprimir un archivo tar comprimido en bzip2
```bash
~$  tar -xvfj archive.tar.bz2
```

---
Crear un tarball comprimido en gzip.
```bash
~$  tar -cvfz archive.tar.gz dir1
```

---
Descomprimir un archive tar comprimido en gzip.
```bash
~$  tar -xvfz archive.tar.gz
```

---
Crear un archivo comprimido en zip.
```bash
~$  zip file1.zip file1
```

---
Comprimir, en zip, varios archivos y directorios de forma simult�nea.
```bash
~$  zip -r file1.zip file1 file2 dir1
```

---
Descomprimir un archivo zip.
```bash
~$  unzip file1.zip
```

# Ver el contenido de un fichero

---
Ver los contenidos de un fichero comenzando desde la primera hilera.
```bash
~$  cat file1
```

---
Ver los contenidos de un fichero comenzando desde la �ltima l�nea.
```bash
~$  tac file1
```

---
Ver el contenido a lo largo de un fichero.
```bash
~$  more file1
```

---
Parecido al commando **more** pero permite salvar el movimiento en el fichero as� como el movimiento hacia atr�s.
```bash
~$  less file1
```

---
Ver las dos primeras l�neas de un fichero.
```bash
~$  head -2 file1
```

---
Ver las dos �ltimas l�neas de un fichero.
```bash
~$  tail -2 file1
```

---
Ver en tiempo real qu� ha sido a�adido al fichero.
```bash
~$  tail -f /var/log/messages
```

# Manipulaci�n de texto

---
Sintaxis general para la manipulaci�n de texto utilizando pipe, stdin y stdout.
```bash
~$  cat file1 file2 .. | command <> file1_in.txt_or_file1_out.txt
```

---
Sintaxis general para manipular un texto de un fichero y escribir el resultado en un fichero nuevo.
```bash
~$  cat file1 | command( sed, grep, awk, grep, etc�) > result.txt
```

---
Sintaxis general para manipular un texto de un fichero y a�adir resultado en un fichero existente.
```bash
~$  cat file1 | command( sed, grep, awk, grep, etc�) � result.txt
```

---
Buscar palabras **aug** en el fichero **/var/log/messages**.
```bash
~$  grep Aug /var/log/messages
```

---
Buscar palabras que comienzan con **aug** en fichero **/var/log/messages**.
```bash
~$  grep ^Aug /var/log/messages
```

---
Seleccionar todas las l�neas del fichero **/var/log/messages** que contienen n�meros.
```bash
~$  grep [0-9] /var/log/messages
```

---
Buscar la cadena **aug** en el directorio **/var/log** y debajo.
```bash
~$  grep Aug -R /var/log/*
```

---
Reubicar **string1** con **string2** en ejemplo.txt
```bash
~$  sed �s/stringa1/stringa2/g� example.txt
```

---
Eliminar todas las l�neas en blanco desde el ejemplo.txt
```bash
~$  sed �/^$/d� example.txt
```

---
Eliminar comentarios y l�neas en blanco de ejemplo.txt
```bash
~$  sed �/ *#/d; /^$/d� example.txt
```

---
Convertir min�sculas en may�sculas.
```bash
~$  echo �esempio� | tr �[:lower:]� �[:upper:]�
```

---
Elimina la primera l�nea del fichero ejemplo.txt
```bash
~$  sed -e �1d� result.txt
```

---
Visualizar solamente las l�neas que contienen la palabra **string1**.
```bash
~$  sed -n �/stringa1/p�
```

# Establecer caracter y conversi�n de ficheros

---
Convertir un formato de fichero texto desde msdos a unix.
```bash
~$  dos2unix filedos.txt fileunix.txt
```

---
Convertir un formato de fichero de texto desde unix a msdos.
```bash
~$  unix2dos fileunix.txt filedos.txt
```

---
Convertir un fichero de texto en html.
```bash
~$  recode ..HTML < page.txt > page.html
```

---
Mostrar todas las conversiones de formato disponibles.
```bash
~$  recode -l | more
```

# An�lisis del sistema de ficheros

---
Chequear los bloques defectuosos en el disco hda1.
```bash
~$  badblocks -v /dev/hda1
```

---
Reparar / chequear la integridad del fichero del sistema linuxen el disco hda1.
```bash
~$  fsck /dev/hda1
```

---
Reparar / chequear la integridad del fichero del sistema ext 2en el disco hda1.
```bash
~$  fsck.ext2 /dev/hda1
```

---
Reparar / chequear la integridad del fichero del sistema ext 2en el disco hda1.
```bash
~$  e2fsck /dev/hda1
```

---
Reparar / chequear la integridad del fichero del sistema ext 3en el disco hda1.
```bash
~$  e2fsck -j /dev/hda1
```

---
Reparar / chequear la integridad del fichero del sistema ext 3en el disco hda1.
```bash
~$  fsck.ext3 /dev/hda1
```

---
Reparar / chequear la integridad del fichero sistema fat en eldisco hda1.
```bash
~$  fsck.vfat /dev/hda1
```

---
Reparar / chequear la integridad de un fichero del sistema dosen el disco hda1.
```bash
~$  fsck.msdos /dev/hda1
```

---
Reparar / chequear la integridad de un fichero del sistema dosen el disco hda1.
```bash
~$  dosfsck /dev/hda1
```

# Formatear un sistema de ficheros

---
Crear un fichero de sistema tipo linux en la partici�n hda1.
```bash
~$  mkfs /dev/hda1
```

---
Crear un fichero de sistema tipo linux ext 2 en hda1.
```bash
~$  mke2fs /dev/hda1
```

---
Crear un fichero de sistema tipo linux ext3 (peri�dico) en la partici�n hda1.
```bash
~$  mke2fs -j /dev/hda1
```

---
Crear un fichero de sistema fat32 en hda1.
```bash
~$  mkfs -t vfat 32 -F /dev/hda1
```

---
Formatear un disco flooply.
```bash
~$  fdformat -n /dev/fd0
```

---
Crear un fichero de sistema swap.
```bash
~$  mkswap /dev/hda3
```

# Trabajo con la SWAP

---
Crear fichero de sistema swap.
```bash
~$  mkswap /dev/hda3
```

---
Activando una nueva partici�n swap.
```bash
~$  swapon /dev/hda3
```

---
Activar dos particiones swap.
```bash
~$  swapon /dev/hda2 /dev/hdb3
```

# Salvas (Backup)

Hacer una salva completa del directorio **/home**.
```bash
~$  dump -0aj -f /tmp/home0.bak /home
```

---
Hacer una salva incremental del directorio **/home**.
```bash
~$  dump -1aj -f /tmp/home0.bak /home
```

---
Restaurando una salva interactivamente.
```bash
~$  restore -if /tmp/home0.bak
```

---
Sincronizaci�n entre directorios.
```bash
~$  rsync -rogpav �delete /home /tmp
```

---
rsync a trav�s del t�nel SSH.
```bash
~$  rsync -rogpav -e ssh �delete /home ip_address:/tmp
```

---
Sincronizar un directorio local con un directorio remoto a trav�s de ssh y de compresi�n.
```bash
~$  rsync -az -e ssh �delete ip_addr:/home/public /home/local
```

---
Sincronizar un directorio remoto con un directorio local a trav�s de ssh y de compresi�n.
```bash
~$  rsync -az -e ssh �delete /home/local ip_addr:/home/public
```

---
Hacer una salva de un disco duro en un host remoto a trav�s dessh.
```bash
~$  dd bs=1M if=/dev/hda | gzip | ssh user@ip_addr �dd of=hda.gz�
```

---
Salvar el contenido de un disco duro a un fichero. (en este caso el disco duro es **sda** y el fichero **file1**).
```bash
~$  dd if=/dev/sda of=/tmp/file1
```

---
Hacer una salva incremental del directorio **/home/user**.
```bash
~$  tar -Puf backup.tar /home/user
```

---
Copiar el contenido de un directorio en un directorio remoto atrav�s de ssh.
```bash
~$  ( cd /tmp/local/ && tar c . ) | ssh -C user@ip_addr �cd /home/share/ && tar x -p�
```

---
Copiar un directorio local en un directorio remoto a trav�s dessh.
```bash
~$  ( tar c /home ) | ssh -C user@ip_addr �cd /home/backup-home && tar x -p�
```

---
Copia local conservando las licencias y enlaces desde un directorio a otro.
```bash
~$  tar cf � . | (cd /tmp/backup ; tar xf � )
```

---
Encontrar y copiar todos los ficheros con extensi�n **.txt** de un directorio a otro.
```bash
~$  find /home/user1 -name �*.txt� | xargs cp -av �target-directory=/home/backup/ �parents
```

---
Encontrar todos los ficheros con extensi�n **.log** y hacer un archivo bzip.
```bash
~$  find /var/log -name �*.log� | tar cv �files-from=- | bzip2> log.tar.bz2
```

---
Hacer una copia del mrb (master boot record) a un disco floppy.
```bash
~$  dd if=/dev/hda of=/dev/fd0 bs=512 count=1
```

---
Restaurar la copia del mbr (master boot record) salvada en un floppy.
```bash
~$  dd if=/dev/fd0 of=/dev/hda bs=512 count=1
```

# CD-ROM

---
Limpiar o borrar un cd regrabable.
```bash
~$  cdrecord -v gracetime=2 dev=/dev/cdrom -eject blank=fast -force
```

---
Crear una imagen iso de cdrom en disco.
```bash
~$  mkisofs /dev/cdrom > cd.iso
```

---
Crear una imagen comprimida iso de cdrom en disco.
```bash
~$  mkisofs /dev/cdrom | gzip > cd_iso.gz
```

---
Crear una imagen iso de un directorio.
```bash
~$  mkisofs -J -allow-leading-dots -R -V �Label CD� -iso-level 4 -o ./cd.iso data_cd
```

---
Quemar una imagen iso.
```bash
~$  cdrecord -v dev=/dev/cdrom cd.iso
```

---
Quemar una imagen iso comprimida.
```bash
~$  gzip -dc cd_iso.gz | cdrecord dev=/dev/cdrom �
```

---
Montar una imagen iso.
```bash
~$  mount -o loop cd.iso /mnt/iso
```

---
Llevar canciones de un cd a ficheros wav.
```bash
~$  cd-paranoia -B
```

---
Llevar las 3 primeras canciones de un cd a ficheros wav.
```bash
~$  cd-paranoia � �-3�
```

---
Escanear bus para identificar el canal scsi.
```bash
~$  cdrecord �scanbus
```

---
Hacer funcionar un md5sum en un dispositivo, como un cd.
```bash
~$  dd if=/dev/hdc | md5sum
```

# Paquetes Deb (Debian, Ubuntu y derivados)

---
Instalar / actualizar un paquete deb.
```bash
~$  dpkg -i package.deb
```

---
Eliminar un paquete deb del sistema.
```bash
~$  dpkg -r package_name
```

---
Mostrar todos los paquetes deb instalados en el sistema.
```bash
~$  dpkg -l
```

---
Mostrar todos los paquetes deb con el nombre **httpd**.
```bash
~$  dpkg -l | grep httpd
```

---
Obtener informaci�n en un paquete espec�fico instalado en el sistema.
```bash
~$  dpkg -s package_name
```

---
Mostar lista de ficheros dados por un paquete instalado en el sistema.
```bash
~$  dpkg -L package_name
```

---
Mostrar lista de ficheros dados por un paquete no instalado todav�a.
```bash
~$  dpkg �contents package.deb
```

---
Verificar cu�l paquete pertenece a un fichero dado.
```bash
~$  dpkg -S /bin/ping
```

# Actualizador de paquetes APT (Debian, Ubuntu y derivados)

---
Instalar / actualizar un paquete deb.
```bash
~$  apt-get install package_name
```

---
Instalar / actualizar un paquete deb desde un cdrom.
```bash
~$  apt-cdrom install package_name
```

---
Actualizar la lista de paquetes.
```bash
~$  apt-get update
```

---
Actualizar todos los paquetes instalados.
```bash
~$  apt-get upgrade
```

---
Eliminar un paquete deb del sistema.
```bash
~$  apt-get remove package_name
```

---
Verificar la correcta resoluci�n de las dependencias.
```bash
~$  apt-get check
```

---
Limpiar cache desde los paquetes descargados.
```bash
~$  apt-get clean
```

---
Retorna lista de paquetes que corresponde a la serie �paquetesbuscados�.
```bash
~$  apt-cache search searched-package
```

# Trabajo con la RED ( LAN y Wi-Fi)

---
Mostrar la configuraci�n de una tarjeta de red ethernet.
```bash
~$  ifconfig eth0
```

---
Activar una interface **eth0**.
```bash
~$  ifup eth0
```

---
Deshabilitar una interface **eth0**.
```bash
~$  ifdown eth0
```

---
Configurar una direcci�n ip.
```bash
~$  ifconfig eth0 192.168.1.1 netmask 255.255.255.0
```

---
Configurar **eth0** en modo com�n para obtener los paquetes (sniffing).
```bash
~$  ifconfig eth0 promisc
```

---
Activar la interface **eth0** en modo dhcp.
```bash
~$  dhclient eth0
```

---
Mostrar mesa de recorrido.
```bash
~$  route -n
```

---
Configurar entrada predeterminada.
```bash
~$  route add -net 0/0 gw IP_Gateway
```

---
Configurar ruta est�tica para buscar la red **192.168.0.0/16**.
```bash
~$  route add -net 192.168.0.0 netmask 255.255.0.0 gw 192.168.1.1
```

---
Eliminar la ruta est�tica.
```bash
~$  route del 0/0 gw IP_gateway
```

---
Activar el recorrido ip.
```bash
~$  echo �1� > /proc/sys/net/ipv4/ip_forward
```

---
Mostrar el nombre del host del sistema.
```bash
~$  hostname
```

---
Buscar el nombre del host para resolver el nombre a una direcci�n ip(1).
```bash
~$  host www.example.com
```

---
Buscar el nombre del host para resolver el nombre a una direcci�m ip y viceversa(2).
```bash
~$  nslookup www.example.com
```

---
Mostar el estado de enlace de todas las interfaces.
```bash
~$  ip link show
```

---
Mostar el estado de enlace de **eth0**.
```bash
~$  mii-tool eth0
```

---
Mostrar las estad�sticas de tarjeta de red **eth0**Establecer .
```bash
~$  ethtool eth0
```

---
Mostrar todas las conexiones de red activas y sus pid.
```bash
~$  netstat -tup
```

---
Mostrar todos los servicios de escucha de red en el sistema y sus pid.
```bash
~$  netstat -tupl
```

---
Mostrar todo el tr�fico http.
```bash
~$  tcpdump tcp port 80
```

---
Mostrar las redes inal�mbricas.
```bash
~$  iwlist scan
```

---
Mostrar la configuraci�n de una tarjeta de red inal�mbrica.
```bash
~$  iwconfig eth1
```

---
Buscar en base de datos whois.
```bash
~$  whois www.example.com
```

# Tablas IP (CORTAFUEGOS)

---
Mostrar todas las cadenas de la tabla de filtro.
```bash
~$  iptables -t filter -L
```

---
Mostrar todas las cadenas de la tabla nat.
```bash
~$  iptables -t nat -L
```

---
Limpiar todas las reglas de la tabla de filtro.
```bash
~$  iptables -t filter -F
```

---
Limpiar todas las reglas de la tabla nat.
```bash
~$  iptables -t nat -F
```

---
Borrar cualquier cadena creada por el usuario.
```bash
~$  iptables -t filter -X
```

---
Permitir las conexiones telnet para entar.
```bash
~$  iptables -t filter -A INPUT -p tcp �dport telnet -j ACCEPT
```

---
Bloquear las conexiones http para salir.
```bash
~$  iptables -t filter -A OUTPUT -p tcp �dport http -j DROP
```

---
Permitir las conexiones pop a una cadena delantera.
```bash
~$  iptables -t filter -A FORWARD -p tcp �dport pop3 -j ACCEPT
```

---
Registrando una cadena de entrada.
```bash
~$  iptables -t filter -A INPUT -j LOG �log-prefix �DROP INPUT�
```

---
Configurar un pat (puerto de traducci�n de direcci�n) en eth0, ocultando los paquetes de salida forzada.
```bash
~$  iptables -t nat -A POSTROUTING -o eth0 -j MASQUERADE
```

---
Redireccionar los paquetes diriguidos de un host a otro.
```bash
~$  iptables -t nat -A PREROUTING -d 192.168.0.1 -p tcp -m tcp �dport 22 -j DNAT �to-destination 10.0.0.2:22
```

# Otros comandos �tiles

---
Mostrar una lista de comandos que pertenecen a las palabras claves de un programa; son �tiles cuando t� sabes qu� hace tu programa, pero de sconoces elnombre del comando.
```bash
~$  apropos ...keyword
```

---
Mostrar las p�ginas del manual on-line; por ejemplo, en un comando ping, usar la opci�n **-k** para encontrar cualquier comando relacionado.
```bash
~$  man ping
```

---
Muestra la descripci�n de lo que hace el programa.
```bash
~$  whatis ...keyword
```

---
Crear un floppy boteable.
```bash
~$  mkbootdisk �device /dev/fd0 `uname -r`
```

---
Codificar un fichero con guardia de seguridad gnu.
```bash
~$  gpg -c file1
```

---
Decodificar un fichero con guardia de seguridad gnu.
```bash
~$  gpg file1.gpg
```

---
Descargar un sitio web completo.
```bash
~$  wget -r www.example.com
```

---
Descargar un fichero con la posibilidad de parar la descargar y reanudar m�s tarde.
```bash
~$  wget -c www.example.com/file.iso
```

---
Comenzar una descarga a cualquier hora. En este caso empezar�a a las 9 horas.00
```bash
~$  echo �wget -c www.example.com/files.iso� | at 09:00
```

---
Mostrar las bibliotecas compartidas requeridas por el programa ssh.
```bash
~$  ldd /usr/bin/ssh
```

---
Colocar un alias para un commando �hh= historial.
```bash
~$  alias hh=�history�
```

---
Cambiar el comando shell.
```bash
~$  chsh
```

---
Es un comando adecuado para saber si tienes que hacer remoto en otra terminal.
```bash
~$  chsh �list-shells
```

---
Mostrar quien est� registrado, e imprimir hora del �ltimo sistema de importaci�n, procesos muertos, procesos de registro de sistema, procesos activos producidos por init, funcionamiento actual y �ltimos cambios del reloj del sistema.
```bash
~$  who -a
```