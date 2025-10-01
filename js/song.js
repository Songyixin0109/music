document.addEventListener('DOMContentLoaded', function () {
    var songList = document.querySelector('.songList'),
        btnPlay = songList.querySelectorAll('.btn-play'),
        fixedSong = document.querySelector('.fixedSong audio'),
        songSrc = [
            '音频/C400002Ql2O31rVjxk.m4a',
            '音频/C400003MisS23J9qCK.m4a',
            '音频/C400002GPT5r262kk1.m4a',
            '音频/C400001s58Vv2fVYxw.m4a',
            '音频/C400003OK44N4HvPVn.m4a',
            '音频/C400001e7BU60urhjC.m4a',
            '音频/C400004cZvLj1qDq4A.m4a'
        ]
    btnPlay.forEach((item, index) => {
        item.songSrc = songSrc[index]
    })
    songList.addEventListener('click', function (e) {
        if (e.target.className != 'btn-play') return
        fixedSong.src = e.target.songSrc
        fixedSong.play()
    })
})