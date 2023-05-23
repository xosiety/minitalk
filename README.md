
Ecco una breve spiegazione di come funzionano i seguenti comandi:

signal: signal è una funzione del C utilizzata per gestire i segnali del sistema. Consente di impostare l'handler (gestore) per un determinato segnale in modo che venga eseguita una determinata azione quando il segnale viene ricevuto dal processo.

sigemptyset: sigemptyset è una funzione che svuota (pulisce) un insieme di segnali. Viene utilizzata per inizializzare un insieme di segnali vuoto prima di utilizzarlo con altre funzioni come sigaddset o sigaction.

sigaddset: sigaddset viene utilizzata per aggiungere un segnale specifico a un insieme di segnali. Viene spesso utilizzata insieme a sigemptyset per creare un insieme di segnali personalizzato per la gestione dei segnali.

sigaction: sigaction è una funzione che consente di impostare l'handler (gestore) per un segnale specifico. Può essere utilizzata per modificare il comportamento predefinito di un segnale o per installare un nuovo gestore di segnali personalizzato.

kill: kill è una funzione utilizzata per inviare un segnale a un processo specifico. Può essere utilizzata per inviare segnali predefiniti o personalizzati ad altri processi nel sistema.

getpid: getpid è una funzione che restituisce l'ID del processo corrente. Viene utilizzata per ottenere l'ID del processo in esecuzione al fine di scopi di identificazione o controllo.

malloc: malloc è una funzione del C utilizzata per allocare dinamicamente una determinata quantità di memoria durante l'esecuzione del programma. Viene spesso utilizzata per allocare spazio per strutture dati complesse come array o strutture.

free: free è una funzione che viene utilizzata per deallocare la memoria precedentemente allocata dinamicamente utilizzando malloc. Rilascia la memoria in modo che possa essere riutilizzata in seguito.

pause: pause è una funzione che sospende l'esecuzione del programma fino a quando non viene ricevuto un segnale. Viene spesso utilizzata per bloccare il programma fino all'arrivo di un segnale specifico.

sleep: sleep è una funzione che mette il processo in pausa per un certo numero di secondi. Il processo viene sospeso per la durata specificata come argomento.

usleep: usleep è una funzione simile a sleep, ma mette in pausa il processo per un certo numero di microsecondi anziché secondi.

exit: exit è una funzione che termina l'esecuzione del programma corrente e restituisce un valore di uscita specifico. Viene spesso utilizzata per terminare il programma in modo controllato.

perror: perror è una funzione che stampa un messaggio di errore sulla console, includendo


Ci sono alcune differenze significative tra sigaction e signal:

Gestione dei segnali multipli: signal ha una gestione semplice dei segnali, il che significa che quando viene chiamato per un segnale specifico, il gestore di segnali predefinito viene sostituito con il nuovo gestore specificato. Questo significa che non è possibile gestire separatamente i segnali multipli. Al contrario, sigaction consente di specificare un gestore di segnali separato per ciascun segnale e fornisce maggiore flessibilità nella gestione dei segnali multipli.

Compatibilità portabile: signal ha un comportamento che varia tra le diverse implementazioni del sistema operativo e potrebbe non essere completamente portabile tra le piattaforme. D'altra parte, sigaction offre una maggiore portabilità tra diverse piattaforme e sistemi operativi, in quanto definisce un'interfaccia standardizzata per la gestione dei segnali.

Gestione avanzata dei segnali: sigaction fornisce funzionalità aggiuntive rispetto a signal. Ad esempio, sigaction consente di specificare l'insieme di segnali che devono essere bloccati durante l'esecuzione del gestore del segnale, offrendo maggiore controllo sulla gestione dei segnali. Inoltre, sigaction supporta la gestione dei segnali interrompibili (SA_RESTART flag), consentendo di riprendere automaticamente le chiamate di sistema interrotte dai segnali.

Trattamento dei segnali non mascherabili: signal non fornisce un modo per bloccare segnali specifici che non possono essere mascherati. sigaction, invece, consente di gestire segnali non mascherabili utilizzando il campo sa_sigaction della struttura struct sigaction, che può essere utilizzato per fornire un gestore di segnali più avanzato.

In generale, se si desidera una gestione più avanzata e portabile dei segnali, è consigliato utilizzare sigaction. Tuttavia, se si desidera una gestione più semplice e non è necessaria la portabilità tra diverse piattaforme, signal può essere utilizzato.

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
