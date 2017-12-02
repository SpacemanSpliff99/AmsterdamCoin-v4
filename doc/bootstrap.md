### Bootstrap the Blockchain Synchronization

Normally the PUFFScoin client will download the transaction and network ledger, called the "blockchain", from the PUFFS network by syncing with the other PUFFScoin clients connected to the network. This process can take quite a bit of time as the [Bitcoin blockchain](ADD LINK TO BLOCK EXPLORER) willl growing larger in size for each day of operation. On average, 1,440 blocks will be added to the blockchain daily, along with the data related to every transaction processed during that period. While the PUFFScoin blockchain will be fairly small to begin with, eventually it will reach very large sizes. Bitcoin's blockchain, running for over ten years, is currently approaching 200 MB in size. There is a very safe and quick way to simplify up this process. Users can use a "bootstrap" of the  blockchain to bring their PUFFScoin client up to sync in just a few simple steps.

### Requirements

- A fresh install of the PUFFScoin client software.

### Download the blockchain via the puffscoin.com website ot using a BitTorrent client.

As part of facilitating use of the PUFFScoin Core desktop wallet client, we will offer an [bootstrap file](https://puffscoin.com/core/bootstrap.zip) for blockchain rapid sync that will be updated every two weeks to start. 

We will also offer a torrent file that can be downloaded using a BitTorrent protocol client. Examples of free and safe open source clients are [Deluge](http://deluge-torrent.org/) or [qBittorrent](http://www.qbittorrent.org/). A guide to installing and configuring the torrent clients can be found [here](http://dev.deluge-torrent.org/wiki/UserGuide) for Deluge and on the hosted forum [here](http://qbforums.shiki.hu/) for qBittorrent. A further in-depth tutorial on BitTorrent can be found [here](http://www.howtogeek.com/howto/31846/bittorrent-for-beginners-how-get-started-downloading-torrents/).

With the client installed we'll proceed to download the blockchain torrent file. Use the following magnet link:

	magnet:?xt=urn:btih:2d4e6c1f96c5d5fb260dff92aea4e600227f1aea&dn=bootstrap.dat&tr=udp://tracker.openbittorrent.com:80&tr=udp://tracker.publicbt.com:80&tr=udp://tracker.ccc.de:80&tr=udp://tracker.istole.it:80
	
The torrent client you install will recognize the download of the torrent file. Save the bootstrap.dat file to the folder you use for downloads. The image below shows an example of the torrent download in qBittorrent, with current speed and ETA highlighted.

![Fig2](img/bootstrap2.png)

### Importing the blockchain
Exit the PUFFScoin client software if you have it running. Be sure not to have an actively used wallet in use. We are going to copy the download of the blockchain to the PUFFScoin client data directory. You should run the client software at least once so it can generate the data directory. Copy the downloaded bootstrap.dat file into the PUFFScoin data folder.

Be sure, if you have active wallets, to backup a copy of your wallet.dat file in a safe place before installing the bootstrap file.

**For Windows users:**
Open explorer, and type into the address bar:

	%APPDATA%\PUFFScoin
    
This will open up the data folder. It should look like the image below ***TODO***. Copy over the bootstrap.dat from your download folder to this directory.
![Fig4](img/bootstrap4.png)

**For OSX users:**
Open Finder by pressing Press [shift] + [cmd] + [g] and enter:

	~/Library/Application Support/PUFFScoin/
    
**For Linux users:**
The directory is hidden in your User folder. Go to:

	~/.puffscoin/
    
### Importing the blockchain
Now start the PUFFScoin client software. It should show "Importing blocks from disk" like the image below ***TODO***. 
![Fig5](img/bootstrap5.png)

Wait until the import finishes. The client will download the last days not covered by the import. Congratulations you have successfully imported the blockchain!

### Is this safe?

Yes, the above method is safe. The download contains only raw blockchain data and the client verifies this on import. 

**Do not download the blockchain from unofficial sources, especially if they provide `*.rev` and `*.sst` files. These files are not verified and can contain malicious edits. Download the PUFFScoin bootstrap file from puffscoin.com or links provided by the recognized PUFFScoin developers on our Bitcointalk thread.**
