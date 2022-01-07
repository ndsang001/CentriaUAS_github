var index_slide = 1;
showSlides(index_slide);

/* Show clicked slide dot*/
function currentSlide(n) {
    showSlides(index_slide = n);
}

/* Next and previous control */

function controlSlides(n) {
    showSlides(index_slide += n);
}

/* Show slide */
function showSlides(n) {
    var slides = document.getElementsByClassName('image_slideshow');
    console.log(slides);
    var dots = document.getElementsByClassName('dot');

    if (n > slides.length) {
        index_slide = 1
    }
    if (n < 1) {
        index_slide = slides.length
    }
    for (let i = 0; i < slides.length; ++i) {
        slides[i].style.display = 'none';
    }
    for (let i = 0; i < dots.length; ++i) {
        dots[i].className = dots[i].className.replace('active', '');
    }

    console.log(index_slide - 1);
    console.log(typeof(index_slide));
    console.log(typeof(slides));
    slides[index_slide - 1].style.display = 'block';
    dots[index_slide - 1].className += 'active';
}