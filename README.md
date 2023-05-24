
# 📖 Minitalk

<!-- TOC -->
* [📖 Minitalk](#-minitalk)
* [💡 Introduzione](#-introduzione)
  * [📝 Mandatory part](#-mandatory-part)
  * [⏭️ Bonus](#-bonus)
* [🛠️ Sigaction](#-sigaction)
<!-- TOC -->

# 💡 Introduzione

L'obiettivo del progetto è creare un sistema di trasmissione di messaggi semplice ma funzionale utilizzando i segnali Unix come mezzo di comunicazione. Il mittente invia un messaggio al destinatario convertendo il messaggio in sequenze di segnali.

Ecco un riassunto delle funzioni permesse all'interno del progetto con i relativi link al manuale.

| Funzione                                                                            | Riassunto                                                                                                                                                                                                                                                                   |
|-------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| [`malloc`](https://man7.org/linux/man-pages/man3/free.3.html)                       | La funzione `malloc` viene utilizzata in C per allocare memoria dinamicamente durante l'esecuzione di un programma. Prende come argomento la dimensione in byte della memoria richiesta e restituisce un puntatore alla memoria allocata.                                   |
| [`free`](https://man7.org/linux/man-pages/man3/free.3.html)                         | La funzione `free` viene utilizzata per liberare la memoria precedentemente allocata tramite `malloc` o altre funzioni di allocazione della memoria. Libera la memoria specificata dal puntatore passato come argomento, consentendo al sistema operativo di riutilizzarla. |
| [`write`](https://man7.org/linux/man-pages/man2/write.2.html)                       | La funzione `write` consente di scrivere dati in un file o in un descrittore di file. Prende come argomenti il descrittore di file, il buffer dei dati e la dimensione dei dati da scrivere. Restituisce il numero di byte scritti o -1 in caso di errore.                  |
| [`getpid`](https://man7.org/linux/man-pages/man2/getpid.2.html)                     | La funzione `getpid` restituisce l'ID del processo chiamante. L'ID del processo è un numero univoco assegnato dal sistema operativo a ogni processo in esecuzione nel sistema.                                                                                              |
| [`signal`](https://man7.org/linux/man-pages/man2/signal.2.html)                     | La funzione `signal` viene utilizzata per impostare il comportamento di un programma in risposta a segnali specifici inviati dal sistema operativo o da altri processi. Prende come argomenti il segnale da gestire e il gestore di segnale personalizzato.                 |
| [`sigemptyset & sigaddset`](https://man7.org/linux/man-pages/man3/sigsetops.3.html) | Le funzioni `sigemptyset` e `sigaddset` sono utilizzate per inizializzare e modificare un insieme di segnali. `sigemptyset` svuota un insieme di segnali, mentre `sigaddset` aggiunge un segnale all'insieme.                                                               |
| [`sigaction`](https://man7.org/linux/man-pages/man2/sigaction.2.html)               | La funzione `sigaction` viene utilizzata per impostare il comportamento di un programma in risposta a segnali specifici. Consente di specificare un gestore di segnale personalizzato e altre opzioni per la gestione dei segnali.                                          |
| [`pause`](https://man7.org/linux/man-pages/man2/pause.2.html)                       | La funzione `pause` sospende l'esecuzione di un programma fino a quando non viene ricevuto un segnale. Viene comunemente utilizzata per bloccare un processo fino a quando non viene ricevuto un segnale di terminazione o un altro segnale specificato.                    |
| [`kill`](https://man7.org/linux/man-pages/man2/kill.2.html)                         | La funzione `kill` viene utilizzata per inviare un segnale a un processo specificato da un ID. Può essere utilizzata per inviare segnali di terminazione o per interagire con altri processi.                                                                   |
| [`sleep`](https://man7.org/linux/man-pages/man3/sleep.3.html)                       | La funzione `sleep` sospende l'esecuzione di un programma per un numero specificato di secondi. È utile per introdurre un ritardo nell'esecuzione di un programma o per attendere un certo periodo di tempo.                                                                |
| [`usleep`](https://man7.org/linux/man-pages/man3/usleep.3.html)                     | La funzione `usleep` sospende l'esecuzione di un programma per un numero specificato di microsecondi. Funziona in modo simile alla funzione `sleep`, ma accetta una frazione di secondo più piccola come argomento.                                                         |                                                                                                                                                                  
| [`exit`](https://man7.org/linux/man-pages/man3/exit.3.html)                         | La funzione `exit` viene utilizzata per terminare l'esecuzione di un programma in modo volontario. Può anche essere utilizzata per restituire un codice di stato al sistema operativo.                                                                                   

## 📝 Mandatory part

Produrre eseguibili per il server e il client.

Il client deve comunicare una stringa passata come parametro al server (identificato dal suo ID di processo), che la visualizza successivamente utilizzando solo i segnali SIGUSR1 e SIGUSR2.

In Unix, i segnali sono meccanismi utilizzati per comunicare con i processi. I segnali sono eventi asincroni che possono essere generati dal kernel del sistema operativo, da altri processi o anche da un processo stesso. Ogni segnale ha un numero di identificazione univoco associato ad esso.

I segnali SIGUSR1 e SIGUSR2 sono segnali definiti dall'utente (User-Defined Signals). Questi segnali sono generalmente utilizzati come meccanismi di comunicazione tra processi o per inviare notifiche personalizzate.

Quando un processo riceve un segnale, può scegliere di gestirlo o ignorarlo. Per gestire un segnale, un processo deve definire un gestore di segnali (signal handler). Un signal handler è una funzione che viene eseguita quando il processo riceve un determinato segnale. Per impostare un signal handler per un segnale specifico, il processo utilizza la funzione di libreria `signal()`.

Ecco un esempio di codice che mostra come impostare e gestire i segnali SIGUSR1 e SIGUSR2 in C utilizzando la funzione `signal()`:

```c
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

// Signal handler per SIGUSR1
void sigusr1_handler(int signum) {
    printf("Ricevuto SIGUSR1\n");
    // Esegui le azioni desiderate
}

// Signal handler per SIGUSR2
void sigusr2_handler(int signum) {
    printf("Ricevuto SIGUSR2\n");
    // Esegui le azioni desiderate
}

int main() {
    // Imposta i signal handler per SIGUSR1 e SIGUSR2
    signal(SIGUSR1, sigusr1_handler);
    signal(SIGUSR2, sigusr2_handler);

    // Esegui il programma
    while(1) {
        // Esegui le azioni del programma
        sleep(1);
    }

    return 0;
}
```

Nell'esempio sopra, vengono definiti due signal handler: `sigusr1_handler()` per SIGUSR1 e `sigusr2_handler()` per SIGUSR2. Questi signal handler vengono quindi associati ai segnali corrispondenti utilizzando `signal(SIGUSR1, sigusr1_handler)` e `signal(SIGUSR2, sigusr2_handler)`.

Il programma entra quindi in un ciclo while che esegue le azioni principali. Nel frattempo, se il processo riceve SIGUSR1 o SIGUSR2, verranno eseguiti i rispettivi signal handler.

## ⏭️ Bonus

Per quel che riguarda la parte bonus andremo ad aggiungere una funzione di conferma di ricezione.
Il progetto bonus dovrá supportare anche caratteri Unicode. 
Sará fondamentale conoscere le differenze tra *sigaction* e *signal*

Ecco una tabella che evidenzia le differenze tra `signal` e `sigaction`:

| Caratteristica                                                              | `signal`                                    | `sigaction`                                                                                                                    |
|-----------------------------------------------------------------------------|---------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------|
| Tipo di gestore di segnali                                                  | Puntatore a funzione (`void (*handler)()`)  | Struttura `struct sigaction` contenente un membro `sa_handler` che può essere un puntatore a funzione                          |
| Gestione dell'insieme dei segnali bloccati durante l'esecuzione del gestore | Non specificato                             | `struct sigaction` contiene un membro `sa_mask` per l'insieme dei segnali bloccati durante l'esecuzione del gestore di segnali |
| Opzioni aggiuntive                                                          | Non specificato                             | `struct sigaction` contiene un membro `sa_flags` per specificare opzioni aggiuntive                                            |
| Compatibilità                                                               | Standard ANSI C                             | Standard POSIX                                                                                                                 |
| Comportamento predefinito per i segnali ignorati                            | Reimposta al comportamento predefinito      | Non reimposta il comportamento predefinito per i segnali ignorati                                                              |
| Compatibilità con altre chiamate di sistema che utilizzano segnali          | Potenziali problemi di compatibilità        | Meno probabilità di problemi di compatibilità                                                                                  |

È importante notare che le differenze possono variare a seconda del sistema operativo e delle implementazioni specifiche.

# 🛠️ Sigaction

    #include <stdio.h>
    #include <stdlib.h>
    #include <signal.h>

    void signalHandler(int signal) {
        printf("Ricevuto segnale %d\n", signal);
    // Azioni da eseguire in risposta al segnale ricevuto
    }

    int main() {
        struct sigaction sa;
        sa.sa_handler = signalHandler;  // Imposta il gestore di segnali personalizzato
        sigemptyset(&sa.sa_mask);       // Svuota l'insieme di segnali bloccati durante l'esecuzione del gestore
        sa.sa_flags = 0;                // Nessuna opzione aggiuntiva

    // Installa il gestore di segnali personalizzato per il segnale specifico
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("Errore nell'installazione del gestore di segnali");
        exit(EXIT_FAILURE);
    }

    // Resto del codice del programma

    return 0;
    }

Nell'esempio sopra, signalHandler è una funzione definita dall'utente che viene eseguita quando il segnale specificato (SIGINT nel caso sopra) viene ricevuto dal processo.

La struttura struct sigaction viene utilizzata per configurare il comportamento di sigaction. Puoi impostare sa_handler con il puntatore alla funzione che gestirà il segnale. 

L'insieme sa_mask può essere utilizzato per specificare un insieme di segnali che devono essere bloccati durante l'esecuzione del gestore del segnale. sa_flags può essere utilizzato per specificare opzioni aggiuntive, se necessario.

Nel nostro esempio, viene utilizzata la funzione sigemptyset per svuotare l'insieme dei segnali bloccati durante l'esecuzione. 

Infine, la funzione sigaction viene chiamata per installare il gestore di segnali personalizzato (signalHandler) per il segnale specificato (SIGINT). 
Se l'installazione fallisce, verrà restituito -1 e verrà stampato un messaggio di errore.

Dopo l'installazione del gestore di segnali, il programma può continuare con il resto del suo codice. Quando il segnale specificato viene ricevuto, la funzione signalHandler verrà chiamata, consentendo di eseguire le azioni desiderate in risposta al segnale.

