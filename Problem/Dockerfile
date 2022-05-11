ARG IMAGE
FROM $IMAGE

ARG USER
ARG EXEC

RUN dpkg --add-architecture i386 && \
    rm -rf /var/lib/apt/lists/* && \
    sed -i 's/archive.ubuntu.com/mirror.kakao.com/g' /etc/apt/sources.list && \
    sed -i 's/security.ubuntu.com/mirror.kakao.com/g' /etc/apt/sources.list
RUN apt update; apt upgrade -y; \
    apt install -y libc6:i386 libncurses5:i386 libstdc++6:i386 socat

RUN adduser --no-create-home --disabled-login --force-badname --gecos '' -- "$USER"
ADD ./$EXEC/$EXEC /home/$USER/$EXEC
ADD ./$EXEC/flag /home/$USER/flag

WORKDIR /home/$USER

RUN chown -R root:$USER /home/$USER && \
    chmod -R 750 /home/$USER

RUN echo "socat TCP-LISTEN:8080,reuseaddr,fork EXEC:/home/$EXEC/$EXEC,nofork,stderr,setsid,su=$EXEC" > /start.sh; chmod 750 /start.sh 
RUN cat /start.sh

CMD ["sh", "/start.sh"]
