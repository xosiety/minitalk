
Ecco una breve spiegazione di come funzionano i seguenti comandi:

- [`malloc`](https://man7.org/linux/man-pages/man3/free.3.html)
- [`free`](https://man7.org/linux/man-pages/man3/free.3.html)
- [`write`](https://man7.org/linux/man-pages/man2/write.2.html)
- [`getpid`](https://man7.org/linux/man-pages/man2/getpid.2.html)
- [`signal`](https://man7.org/linux/man-pages/man2/signal.2.html)
- [`sigemptyset & sigaddset`](https://man7.org/linux/man-pages/man3/sigsetops.3.html)
- [`sigaction`](https://man7.org/linux/man-pages/man2/sigaction.2.html)
- [`pause`](https://man7.org/linux/man-pages/man2/pause.2.html)
- [`kill`](https://man7.org/linux/man-pages/man2/kill.2.html)
- [`sleep`](https://man7.org/linux/man-pages/man3/sleep.3.html)
- [`usleep`](https://man7.org/linux/man-pages/man3/usleep.3.html)
- [`exit`](https://man7.org/linux/man-pages/man3/exit.3.html)


Ecco un riassunto delle funzioni permesse all'interno del progetto con i relativi link al manuale.

| Funzione | Riassunto |
|----------|-----------|
| malloc   | La funzione `malloc` viene utilizzata in C per allocare memoria dinamicamente durante l'esecuzione di un programma. Prende come argomento la dimensione in byte della memoria richiesta e restituisce un puntatore alla memoria allocata. |
| free     | La funzione `free` viene utilizzata per liberare la memoria precedentemente allocata tramite `malloc` o altre funzioni di allocazione della memoria. Libera la memoria specificata dal puntatore passato come argomento, consentendo al sistema operativo di riutilizzarla. |
| write    | La funzione `write` consente di scrivere dati in un file o in un descrittore di file. Prende come argomenti il descrittore di file, il buffer dei dati e la dimensione dei dati da scrivere. Restituisce il numero di byte scritti o -1 in caso di errore. |
| getpid   | La funzione `getpid` restituisce l'ID del processo chiamante. L'ID del processo è un numero univoco assegnato dal sistema operativo a ogni processo in esecuzione nel sistema. |
| signal   | La funzione `signal` viene utilizzata per impostare il comportamento di un programma in risposta a segnali specifici inviati dal sistema operativo o da altri processi. Prende come argomenti il segnale da gestire e il gestore di segnale personalizzato. |
| sigemptyset & sigaddset | Le funzioni `sigemptyset` e `sigaddset` sono utilizzate per inizializzare e modificare un insieme di segnali. `sigemptyset` svuota un insieme di segnali, mentre `sigaddset` aggiunge un segnale all'insieme. |
| sigaction | La funzione `sigaction` viene utilizzata per impostare il comportamento di un programma in risposta a segnali specifici. Consente di specificare un gestore di segnale personalizzato e altre opzioni per la gestione dei segnali. |
| pause    | La funzione `pause` sospende l'esecuzione di un programma fino a quando non viene ricevuto un segnale. Viene comunemente utilizzata per bloccare un processo fino a quando non viene ricevuto un segnale di terminazione o un altro segnale specificato. |
| kill     | La funzione `kill` viene utilizzata per inviare un segnale a un processo specificato da un ID di processo. Può essere utilizzata per inviare segnali di terminazione o per interagire con altri processi. |
| sleep    | La funzione `sleep` sospende l'esecuzione di un programma per un numero specificato di secondi. È utile per introdurre un ritardo nell'esecuzione di un programma o per attendere un certo periodo di tempo. |
| usleep   | La funzione `usleep` sospende l'esecuzione di un programma per un numero specificato di microsecondi. Funz

iona in modo simile alla funzione `sleep`, ma accetta una frazione di secondo più piccola come argomento. |
| exit     | La funzione `exit` viene utilizzata per terminare l'esecuzione di un programma in modo volontario. Può anche essere utilizzata per restituire un codice di stato al sistema operativo. |

Ci sono alcune differenze significative tra sigaction e signal:

Gestione dei segnali multipli: signal ha una gestione semplice dei segnali, il che significa che quando viene chiamato per un segnale specifico, il gestore di segnali predefinito viene sostituito con il nuovo gestore specificato. Questo significa che non è possibile gestire separatamente i segnali multipli. Al contrario, sigaction consente di specificare un gestore di segnali separato per ciascun segnale e fornisce maggiore flessibilità nella gestione dei segnali multipli.

Compatibilità portabile: signal ha un comportamento che varia tra le diverse implementazioni del sistema operativo e potrebbe non essere completamente portabile tra le piattaforme. D'altra parte, sigaction offre una maggiore portabilità tra diverse piattaforme e sistemi operativi, in quanto definisce un'interfaccia standardizzata per la gestione dei segnali.

Gestione avanzata dei segnali: sigaction fornisce funzionalità aggiuntive rispetto a signal. Ad esempio, sigaction consente di specificare l'insieme di segnali che devono essere bloccati durante l'esecuzione del gestore del segnale, offrendo maggiore controllo sulla gestione dei segnali. Inoltre, sigaction supporta la gestione dei segnali interrompibili (SA_RESTART flag), consentendo di riprendere automaticamente le chiamate di sistema interrotte dai segnali.

Trattamento dei segnali non mascherabili: signal non fornisce un modo per bloccare segnali specifici che non possono essere mascherati. sigaction, invece, consente di gestire segnali non mascherabili utilizzando il campo sa_sigaction della struttura struct sigaction, che può essere utilizzato per fornire un gestore di segnali più avanzato.

In generale, se si desidera una gestione più avanzata e portabile dei segnali, è consigliato utilizzare sigaction. Tuttavia, se si desidera una gestione più semplice e non è necessaria la portabilità tra diverse piattaforme, signal può essere utilizzato.

Ecco una tabella che mostra le differenze tra `signal` e `sigaction`:

| Caratteristica                | `signal`                                  | `sigaction`                                                                                                  |
|-------------------------------|-------------------------------------------|--------------------------------------------------------------------------------------------------------------|
| Tipo di gestore di segnali   | Puntatore a funzione (`void (*handler)()`) | Struttura `struct sigaction` contenente un membro `sa_handler` che può essere un puntatore a funzione        |
| Gestione dell'insieme dei segnali bloccati durante l'esecuzione del gestore | Non specificato                             | `struct sigaction` contiene un membro `sa_mask` per l'insieme dei segnali bloccati durante l'esecuzione del gestore di segnali |
| Opzioni aggiuntive            | Non specificato                             | `struct sigaction` contiene un membro `sa_flags` per specificare opzioni aggiuntive                            |
| Compatibilità                  | Standard ANSI C                           | Standard POSIX                                                                                                |
| Comportamento predefinito per i segnali ignorati | Reimposta al comportamento predefinito       | Non reimposta il comportamento predefinito per i segnali ignorati                                               |
| Compatibilità con altre chiamate di sistema che utilizzano segnali | Potenziali problemi di compatibilità            | Meno probabilità di problemi di compatibilità                                                                  |

È importante notare che le differenze possono variare a seconda del sistema operativo e delle implementazioni specifiche.

Ecco una spiegazione dettagliata su come utilizzare sigaction:

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


Nell'esempio sopra, signalHandler è una funzione definita dall'utente che viene eseguita quando il segnale specificato (SIGINT nel caso sopra) viene ricevuto dal processo. Puoi personalizzare questa funzione per eseguire azioni specifiche in risposta al segnale ricevuto.

La struttura struct sigaction viene utilizzata per configurare il comportamento di sigaction. Puoi impostare sa_handler con il puntatore alla funzione che gestirà il segnale. L'insieme sa_mask può essere utilizzato per specificare un insieme di segnali che devono essere bloccati durante l'esecuzione del gestore del segnale. sa_flags può essere utilizzato per specificare opzioni aggiuntive, se necessario.

Nel nostro esempio, viene utilizzata la funzione sigemptyset per svuotare l'insieme dei segnali bloccati durante l'esecuzione del gestore di segnali. Infine, la funzione sigaction viene chiamata per installare il gestore di segnali personalizzato (signalHandler) per il segnale specificato (SIGINT). Se l'installazione fallisce, verrà restituito -1 e verrà stampato un messaggio di errore.

Dopo l'installazione del gestore di segnali, il programma può continuare con il resto del suo codice. Quando il segnale specificato viene ricevuto, la funzione signalHandler verrà chiamata, consentendo di eseguire le azioni desiderate in risposta al segnale.
